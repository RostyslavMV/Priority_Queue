#pragma once
#include <cmath>
class Shape
{
protected:
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
	double FunctionLength(double a, double b,int n, double(*f)(double x))
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
};

// class of shape between function and X axis
class ShapeX: public Shape
{
private:
	double(*function)(double x);
	void CalculateArea() override
	{
		this->area = SimpsonMethod(x1, x2, (x2 - x1 + 1) * this->n, function);
	}
	void CalculatePerimeter() override
	{
		this->perimeter = 0;
		this->perimeter += x2 - x1 + function(x1)+function(x2);
		this->perimeter += FunctionLength(x1, x2, (x2 - x1 + 1) * this->n, function);
	}
public:
	ShapeX(double x1, double x2, double(*function)(double x))
	{
		this->x1 = x1;
		this->x2 = x2;
		if (x1 > x2)
		{
			int temp = x1;
			x1 = x2;
			x2 = temp;
		}
		this->function = function;
		CalculateArea();
		CalculatePerimeter();
	}
	ShapeX(double x1, double x2, int n, double(*function)(double x))
	{
		this->x1 = x1;
		this->x2 = x2;
		if (x1 > x2)
		{
			int temp = x1;
			x1 = x2;
			x2 = temp;
		}
		this->function = function;
		this->n = n;
		CalculateArea();
		CalculatePerimeter();
	}
};

class Shape2Functions : public Shape
{
private:
	double(*function1)(double x);
	double(*function2)(double x);
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
	Shape2Functions(int x1, int x2, double(*function1)(double x), double(*function2)(double x))
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
		CalculateArea();
		CalculatePerimeter();
	}
	Shape2Functions(int x1, int x2,int n, double(*function1)(double x), double(*function2)(double x))
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

