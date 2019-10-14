#pragma once
#include <cmath>
#include <iostream>
class Shape
{
protected:
	double(*function1)(double x);
	double(*function2)(double x);
	int n = 10000;
	double x1, x2;
	double area;
	double perimeter;
	double SimpsonMethod(double a, double b, int n, double(*f)(double x))
	{
		double h = (b - a) / n;
		double s = (f(a) + f(b)) * 0.5;
		for (int i = 1; i <= n - 1; i++)
		{
			double xk = a + h * i;
			double xk1 = a + h * (i - 1);
			s += f(xk) + 2 * f((xk1 + xk) / 2);
		}
		double x = a + h * n;
		double x1 = a + h * (n - 1);
		s += 2 * f((x1 + x) / 2);

		return s * h / 3.0;
	}
	double FunctionLength(double a, double b, int n, double(*f)(double x))
	{
		double length = 0;
		double h = (b - a) / n;
		for (int i = 0; i <= n; i++)
		{
			double dy = f(a + h * (i + 1)) - f(a + h * i);
			length += sqrt(dy * dy + h * h);
		}
		return length;
	}
	virtual void CalculateArea() = 0;
	virtual void CalculatePerimeter() = 0;
public:
	double Area()
	{
		return area;
	}
	double Perimeter()
	{
		return perimeter;
	}
	// Change integration step and step used for calculating function length
	void SetN(int n)
	{
		this->n = n;
	}
	double X1()
	{
		return x1;
	}
	double X2()
	{
		return x2;
	}
	double(*Function1())(double x)
	{
		return this->function1;
	}
	double(*Function2())(double x)
	{
		return this->function2;
	}
	friend ostream& operator<<(ostream& os, const Shape& shape);
	bool operator==(const Shape& shape)
	{
		return (area == shape.area);
	}
	friend bool operator> (const Shape& shape1, const Shape& shape2);
};

bool operator> (const Shape& shape1, const Shape& shape2)
{
	return shape1.area > shape2.area;
}
ostream& operator<< (ostream& os, const Shape& shape)
{
	os << "Area: " << shape.area << "; ";
	os << "Perimeter: " << shape.perimeter;
	return os;
}

double ReturnZero(double x)
{
	return 0;
}

// class of shape between function and X axis
class ShapeX : public Shape
{
private:
	void CalculateArea() override
	{
		this->area = SimpsonMethod(x1, x2, (x2 - x1 + 1) * this->n, function1);
	}
	void CalculatePerimeter() override
	{
		this->perimeter = 0;
		this->perimeter += x2 - x1 + function1(x1) + function1(x2);
		this->perimeter += FunctionLength(x1, x2, (x2 - x1 + 1) * this->n, function1);
	}
public:
	ShapeX(double x1, double x2, double(*function)(double x), int n = 10000)
	{
		this->x1 = x1;
		this->x2 = x2;
		if (x1 > x2)
		{
			int temp = x1;
			x1 = x2;
			x2 = temp;
		}
		this->function1 = function;
		this->function2 = ReturnZero;
		this->n = n;
		CalculateArea();
		CalculatePerimeter();
	}
	double(*Function())(double x)
	{
		return this->function1;
	}
};

class Shape2Functions : public Shape
{
private:
	void CalculateArea() override
	{
		double func1Integral = SimpsonMethod(x1, x2, (x2 - x1 + 1) * this->n, function1);
		double func2Integral = SimpsonMethod(x1, x2, (x2 - x1 + 1) * this->n, function2);
		this->area = abs(func1Integral - func2Integral);
	}
	void CalculatePerimeter() override
	{
		this->perimeter = 0;
		this->perimeter += FunctionLength(x1, x2, (x2 - x1 + 1) * this->n, function1);
		this->perimeter += FunctionLength(x1, x2, (x2 - x1 + 1) * this->n, function2);
		this->perimeter += abs(function2(x1) - function1(x1)) + abs(function2(x2) - function1(x2));
	}
public:
	Shape2Functions(int x1, int x2, double(*function1)(double x), double(*function2)(double x),int n = 10000)
	{
		this->x1 = x1;
		this->x2 = x2;
		if (x1 > x2)
		{
			int temp = x1;
			x1 = x2;
			x2 = temp;
		}
		this->function1 = function1;
		this->function2 = function2;
		this->n = n;
		CalculateArea();
		CalculatePerimeter();
	}
};

struct MySegment
{
	double y2; // Higher point
	double y1; //Lower point
	MySegment(double y1, double y2)
	{
		this->y1 = y1;
		this->y2 = y2;
	}
};

class ShapeIntersection : public Shape
{
private:
	Shape* shape1;
	Shape* shape2;
	void CalculateArea() override
	{
		this->area = 0;
		this->perimeter = 0;
		int n = (x2 - x1 + 1) * this->n;
		double h = (x2 - x1) / n;
		double y1 = (shape1->Function1())(x1);
		double y2 = (shape1->Function2())(x1);
		double y3 = (shape2->Function1())(x1);
		double y4 = (shape2->Function2())(x1);
		MySegment segment = getIntersection(y1, y2, y3, y4);
		this->perimeter += segment.y2 - segment.y1;
		y1 = (shape1->Function1())(x2);
		y2 = (shape1->Function2())(x2);
		y3 = (shape2->Function1())(x2);
		y4 = (shape2->Function2())(x2);
		segment = getIntersection(y1, y2, y3, y4);
		this->perimeter += segment.y2 - segment.y1;
		for (int i = 0; i < n - 1; i++)
		{
			y1 = (shape1->Function1())(x1 + h * i);
			y2 = (shape1->Function2())(x1 + h * i);
			y3 = (shape2->Function1())(x1 + h * i);
			y4 = (shape2->Function2())(x1 + h * i);
			segment = getIntersection(y1, y2, y3, y4);
			if (segment.y1 == y1) this->function1 = shape1->Function1();
			else if (segment.y1 == y2) this->function1 = shape1->Function2();
			else if (segment.y1 == y3) this->function1 = shape2->Function1();
			else if (segment.y1 == y4) this->function1 = shape2->Function2();
			if (segment.y2 == y1) this->function2 = shape1->Function1();
			else if (segment.y2 == y2) this->function2 = shape1->Function2();
			else if (segment.y2 == y3) this->function2 = shape2->Function1();
			else if (segment.y2 == y4) this->function2 = shape2->Function2();
			this->area += SimpsonMethod(x1 + h * i, x1 + h * (i + 1), 1, this->function2) -
				SimpsonMethod(x1 + h * i, x1 + h * (i + 1), 1, this->function1);
			this->perimeter += FunctionLength(x1 + h * i, x1 + h * (i + 1), 1, function1);
			this->perimeter += FunctionLength(x1 + h * i, x1 + h * (i + 1), 1, function2);
		}
	}
	// Primeter is calculated with area simultaneously for this class
	void CalculatePerimeter() override
	{
	}
	MySegment getIntersection(double y1, double y2, double y3, double y4)
	{
		MySegment segment(0, 0);
		if (y1 > y2)
		{
			double temp = y1;
			y1 = y2;
			y2 = temp;
		}
		if (y3 > y4)
		{
			double temp = y3;
			y3 = y4;
			y4 = temp;
		}
		if (y1 >= y3 && y1 <= y4) segment.y1 = y1;
		else if (y3 >= y1 && y3 <= y2) segment.y1 = y3;
		if (y2 <= y4 && y2 >= y3) segment.y2 = y2;
		else if (y4 <= y2 && y4 >= y1) segment.y2 = y4;
		return segment;
	}

public:
	ShapeIntersection(Shape* shape1, Shape* shape2, int n=10000)
	{
		this->shape1 = shape1;
		this->shape2 = shape2;
		MySegment segment = getIntersection(shape1->X1(), shape1->X2(), shape2->X1(), shape2->X2());
		this->x1 = segment.y1;
		this->x2 = segment.y2;
		this->n = n;
		CalculateArea();
	}
};

