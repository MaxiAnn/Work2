#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include "Student.h"

using namespace std;

class Pair
{
public:
	int key;
	Student value;
	Pair()
	{
		key = -1;
	}
	Pair operator = (Pair &st)
	{
		this->key = st.key, this->value = st.value;
		return *this;
	};
	bool operator == (Pair &st)
	{
		if (this->value == st.value)return 1;
		return 0;
	}
	bool operator != (Pair &st)
	{
		if (this->value != st.value)return 1;
		return 0;
	};
	friend ostream & operator << (ostream &os, Pair &St)
	{
		os << "Hash: " << St.key << ", " << "Student: " << St.value << endl;
		return os;
	}	
};

#pragma once
