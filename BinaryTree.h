#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
#include "Student.h"
#include "Baseclass.h"
#include "arrclass.h"
#include "listclass.h"

using namespace std;

template <typename T> class Tree
{
public:
	struct leaf
	{
		leaf *right;
		leaf *left;
		T data;
	};
	leaf *root;
	int size;
	Tree()
	{
		root = nullptr;
		size = 0;
	};
	~Tree()
	{
		delete root;
	};
	void Show_tree(leaf *&leaf1)
	{
		if (leaf1 != nullptr)
		{
			Show_tree(leaf1->left);
			cout << leaf1->data << endl;
			Show_tree(leaf1->right);
		}
	};
	void Add_leaf(leaf *&leaf1, T data)
	{
		if (leaf1 == nullptr)
		{
			leaf1 = new leaf;
			leaf1->data = data;
			leaf1->left = leaf1->right = nullptr;
		}
		if (data < leaf1->data)
		{
			if (leaf1->left != nullptr) {
				Add_leaf(leaf1->left, data);
			}
			else
			{
				leaf1->left = new leaf;
				leaf1->left->left = leaf1->left->right = nullptr;
				leaf1->left->data = data;

			}
		}
		if (data > leaf1->data)
		{
			if (leaf1->right != nullptr)
			{
				Add_leaf(leaf1->right, data);
			}
			else
			{
				leaf1->right = new leaf;
				leaf1->right->left = leaf1->right->right = nullptr;
				leaf1->right->data = data;
			}

		}
		size++;
	};
	void Create(int size, Tree *Tree1, Sequence<T> *p)
	{
		T data;
		for (int i = 0; i<size; i++)
		{
			data = p->Get(i);
			Tree1->Add_leaf(root, data);
		}
	};
	void Search(leaf *&r, string a, int *f)
	{
		if (r == nullptr)
		{
			cout << "The tree is empty" << endl;

		}
		if (r->data.Surname == a)
		{
			cout << "This student is found" << endl;
			cout << r->data;
			(*f)++;
		}

		if (a < r->data.Surname)
		{
			if (r->left != nullptr)
			{
				Search(r->left, a, f);
			}
		}
		else
		{
			if (r->right != nullptr)
			{
				Search(r->right, a, f);
			}
		}
	}
};

#pragma once
