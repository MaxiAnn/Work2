#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <fstream>
#include <Windows.h>
#include <iostream>
#include "Student.h"
#include "Baseclass.h"
#include "arrclass.h"
#include "listclass.h"
#include "MergeSort.h"
#include "BinarySearch.h"
#include "BinaryTree.h"
#include "Hash-table.h"
#include "CompTime.h"

using namespace std;


int main()
{
	UINT ansi = GetACP();
	SetConsoleCP(ansi);
	SetConsoleOutputCP(ansi);
	Sequence <Student> *p = new ListSequence<Student>;
	int N, i;
	Student st;
	cout << "Enter how many students you'd like to put into the table \n";
	cin >> N;
	ifstream fin("ann.txt");
	for (i = 0; i < N; i++)
	{
		fin >> st;
		p->Append(st);
	};
	fin.close();
	cout << "Amount of students in the list: " << p->Getlength(); cout << endl;
	cout << "Choose the searching way: \n 1-Binary search \n 2-Seacrh by Binary tree \n 3-Hash-tables \n";
	int arg;
	cin >> arg;
	Student SStudent;
	char ind;
	if (arg == 1)
	{
		MergeSort(p, 0, p->Getlength() - 1);
		cout << "Enter surname of the student you'd like to find" << endl;
		cin >> SStudent.Surname;
		BinarySearch(p, SStudent.Surname);
		cout << "Would you like to compare the working time of different searching? \n Yes - y \n No - n \n";
		cin >> ind;
		if (ind == 'y')
		{
			Compare_Time(p, SStudent.Surname);
		};
	}
	else
	{
		if (arg == 2)
		{
			Tree <Student> tree;
			tree.Create(p->Getlength(), &tree, p);
			cout << "Enter surname of the student you'd like to find" << endl;
			cin >> SStudent.Surname;
			int f = 0;
			tree.Search(tree.root, SStudent.Surname, &f);
			if (f == 0) { cout << "This student isn't found \n"; };
			cout << "Would you like to compare the working time of different searching? \n Yes - y \n No - n \n";
			cin >> ind;
			if (ind == 'y')
			{
				Compare_Time(p, SStudent.Surname);
			};
		}
		else
		{
			HashTable <Student> Table;
			Student data;
			for (i = 0; i < N; i++)
			{
				data = p->Get(i);
				Table.Add(data);
			};
			cout << "Enter surname of the student you'd like to find" << endl;
			cin >> SStudent.Surname;
			Table.Search(SStudent.Surname);
			//Table.Show_table();
			cout << "Would you like to compare the working time of different searching? \n Yes - y \n No - n \n";
			cin >> ind;
			if (ind == 'y')
			{
				Compare_Time(p, SStudent.Surname);
			};
		}
	}
	system("pause");
	return 0;
}
