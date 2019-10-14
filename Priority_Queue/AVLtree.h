#pragma once
#include <iostream>

using std::cout;

template <class T>
class AVLnode {
public:
	T data;
	int balance;
	AVLnode* left;
	AVLnode* right;
	AVLnode* parent;
	AVLnode(T data, AVLnode* parent)
	{
		this->data = data;
		this->parent = parent;
		balance = 0;
		left = nullptr;
		right = nullptr;
	}
	~AVLnode() {
		delete left;
		delete right;
	}
};

template <class T>
class AVLtree {
public:
	AVLtree()
	{
		root = nullptr;
	}
	~AVLtree()
	{
		delete root;
	}
	bool ²nsert(T data)
	{
		if (root == nullptr)
		{
			root = new AVLnode<T>(data, nullptr);
		}
		else
		{
			AVLnode<T>* n = root, * parent;
			while (true)
			{
				/*if (n->data == data)
					return false;*/
				parent = n;
				bool goLeft = n->data > data;
				n = goLeft ? n->left : n->right;
				if (n == nullptr)
				{
					if (goLeft)
					{
						parent->left = new AVLnode<T>(data, parent);
					}
					else
					{
						parent->right = new AVLnode<T>(data, parent);
					}
					Rebalance(parent);
					break;
				}
			}
		}
		size++;
		return true;
	}
	void DeleteKey(T delKey)
	{
		if (root == nullptr)
			return;
		AVLnode<T>* node = root, * parent = root, * delNode = nullptr, * child = root;
		while (child != nullptr)
		{
			parent = node;
			node = child;
			//child = delKey >= node->data ? node->right : node->left;
			if (delKey > node->data || delKey == node->data) child = node->right;
			else child = node->left;
			if (delKey == node->data)
				delNode = node;
		}
		if (delNode != nullptr)
		{
			delNode->data = node->data;
			child = node->left != nullptr ? node->left : node->right;
			if (root->data == delKey)
			{
				root = child;
			}
			else
			{
				if (parent->left == node)
				{
					parent->left = child;
				}
				else
				{
					parent->right = child;
				}
				Rebalance(parent);
			}
		}
		size--;
	}
	void PrintInorder()
	{
		PrintInorder(root);
	}
	void PrintBalance()
	{
		PrintBalance(root);
	}
	int Size()
	{
		return size;
	}
	AVLnode<T>* Root()
	{
		return root;
	}
	AVLnode<T>* MinNode()
	{
		if (root == nullptr)
			return nullptr;
		AVLnode<T>* current = root;
		while (current->left!=nullptr)
		{
			current = current->left;
		}
		return current;
	}
private:
	int size = 0;
	AVLnode<T>* root;
	AVLnode<T>* RotateLeft(AVLnode<T>* a)
	{
		AVLnode<T>* b = a->right;
		b->parent = a->parent;
		a->right = b->left;
		if (a->right != nullptr)
			a->right->parent = a;
		b->left = a;
		a->parent = b;
		if (b->parent != nullptr)
		{
			if (b->parent->right == a)
			{
				b->parent->right = b;
			}
			else
			{
				b->parent->left = b;
			}
		}
		SetBalance(a);
		SetBalance(b);
		return b;
	}

	AVLnode<T>* RotateRight(AVLnode<T>* a)
	{
		AVLnode<T>* b = a->left;
		b->parent = a->parent;
		a->left = b->right;

		if (a->left != nullptr)
			a->left->parent = a;

		b->right = a;
		a->parent = b;

		if (b->parent != nullptr)
		{
			if (b->parent->right == a)
			{
				b->parent->right = b;
			}
			else
			{
				b->parent->left = b;
			}
		}
		SetBalance(a);
		SetBalance(b);
		return b;
	}

	AVLnode<T>* RotateLeftThenRight(AVLnode<T>* node)
	{
		node->left = RotateLeft(node->left);
		return RotateRight(node);
	}

	AVLnode<T>* RotateRightThenLeft(AVLnode<T>* node)
	{
		node->right = RotateRight(node->right);
		return RotateLeft(node);
	}

	void Rebalance(AVLnode<T>* node)
	{
		SetBalance(node);

		if (node->balance == -2)
		{
			if (Height(node->left->left) >= Height(node->left->right))
				node = RotateRight(node);
			else
				node = RotateLeftThenRight(node);
		}
		else if (node->balance == 2)
		{
			if (Height(node->right->right) >= Height(node->right->left))
				node = RotateLeft(node);
			else
				node = RotateRightThenLeft(node);
		}

		if (node->parent != nullptr)
		{
			Rebalance(node->parent);
		}
		else
		{
			root = node;
		}
	}

	int Height(AVLnode<T>* node)
	{
		if (node == nullptr)
			return -1;
		int hl = Height(node->left);
		int hr = Height(node->right);
		int max = (hl < hr) ? hr : hl;
		return 1 + max;
	}
	void SetBalance(AVLnode<T>* node)
	{
		node->balance = Height(node->right) - Height(node->left);
	}
	void PrintBalance(AVLnode<T>* node)
	{
		if (node != nullptr)
		{
			PrintBalance(node->left);
			cout << node->balance << " ";
			PrintBalance(node->right);
		}
	}
	void PrintInorder(AVLnode<T>* node)
	{
		if (node == nullptr)
			return;
		PrintInorder(node->left);
		cout << node->data << " ";
		PrintInorder(node->right);
	}
};


