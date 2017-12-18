#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <fstream>
#include "Student.h"
#include "Baseclass.h"
#include "arrclass.h"
#include "listclass.h"

template <typename T> void BinarySearch(Sequence <T> *p, string item)
{
	int start = 0, end = p->Getlength() - 1, mid;
	string a;
	bool flag = false;
	while (((end - start) >= 0) && (!flag))
	{
		mid = (start + end) / 2;
		a = (p->Get(mid)).Surname;
		if (a != item)
		{
			if (a > item)
			{
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
			};
		}
		else
		{
			flag = true;
		};
	}
	if (flag)
	{
		cout << "This student is found, his number in list is " << mid+1 << endl;
		cout << p->Get(mid) << endl;
	}
	else
	{
		cout << "This student isn't found" << endl;
	};
}

#pragma once
