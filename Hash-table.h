#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
#include "Student.h"
#include "Baseclass.h"
#include "listclass.h"

using namespace std;

int getHash(string St)
{
	int key = 0;
	unsigned k;
	for (k = 0; k < St.length(); k++)
	{
		key += ((int)St[k])*((int)St[k]);
	}
	key %= 13;
	return key;
}

template <typename T> class HashTable {
private:
	int size;
	ListSequence <Pair> *Array;
public:
	HashTable()
	{
		size = 13;
		Array = new ListSequence <Pair> [size];
	};
	void Add(T &st)
	{
		Pair KeySt;
		KeySt.key = getHash(st.Surname);
		KeySt.value = st;
		Array[KeySt.key].Append(KeySt);
	};
	void Delete(T &st)
	{
		int rkey = getHash(st), i = -1, j = 0;
		Pair item;
		if (Array[rkey]->Getlength() != 0)
		{
			while ((i < 0) && (j < Array[rkey]->Getlength()))
			{
				item = Array[rkey]->Get(j);
				if (item->value == st) { i = j };
			};
			if (i < 0)
			{
				cout << "There is no such student \n";
			}
			else
			{
				Array[rkey]->Remove(st);
				cout << "This student is removed from the table \n";
			}
		};
	};
	void Search(string &st)
	{
		int rkey = getHash(st), i = -1, j = 0;
		Pair item;
		
			if (Array[rkey].Getlength() != 0)
			{
				while ((i < 0) && (j < Array[rkey].Getlength()))
				{
					item = Array[rkey].Get(j);
					if (item.value.Surname == st) { i = j; };
					j++;
				}
			};
			if (i < 0)
			{
				cout << "This student isn't found \n";
			}
			else
			{
				cout << "This student is found \n";
				cout << item.value << endl;
			};
	}
	void Show_table()
	{
		int k;
		for (k = 0; k < 13; k++)
		{
			if (Array[k].Getlength() != 0)
			{
				Array[k].show();
			}
		}
	}
};

#pragma once
