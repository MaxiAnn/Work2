#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
#include "Student.h"
#include "Baseclass.h"
#include "listclass.h"
#include "MergeSort.h"
#include "BinarySearch.h"
#include "BinaryTree.h"
#include "Hash-table.h"
#include <ctime>

using namespace std;

void Compare_Time(Sequence <Student> *p, string st)
{
	double time1, time2, time3, tstart, tend;

	MergeSort(p, 0, p->Getlength() - 1);
	tstart = clock();
	BinarySearch(p, st);
	tend = clock();
	time1 = tend - tstart;

	Tree <Student> tree;
	tree.Create(p->Getlength(), &tree, p);
	int f = 0;
	tstart = clock();
	tree.Search(tree.root, st, &f);
	tend = clock();
	time2 = tend - tstart;

	HashTable <Student> Table;
	int i;
	Student data;
	for (i = 0; i < p->Getlength(); i++)
	{
		data = p->Get(i);
		Table.Add(data);
	};
	tstart = clock();
	Table.Search(st);
	tend = clock();
	time3 = tend - tstart;

	cout << "Working time: \n Binary search - " << time1 << " ms \n Search by tree - " << time2 << " ms \n Hash-tables - " << time3 << " ms \n The fastest way is ";
	if (time1 < time2)
	{
		if (time1 < time3)
		{
			cout << "Binary search \n";
		}
		else
		{
			cout << "Hash-tables \n";
		};
	}
	else
	{
		if (time2 < time3)
		{
			cout << "Search by binary tree \n";
		}
		else
		{
			cout << "Hash-tables \n";
		};
	}
}

#pragma once
