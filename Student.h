#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

class Student
{
public:
	string Name;
	string Surname;
	int age;
	int Group;

	friend ostream & operator << (ostream &os, Student &St)
	{
		os << "Name: " << St.Name << " " << "Surname: " << St.Surname << " " << "Age: " << St.age << " " << "Group: " << St.Group << endl;
		return os; 
	}
	friend istream & operator >> (istream &is, Student &St)
	{
		is >> St.Name;
		is >> St.Surname;
		is >> St.age;
		is >> St.Group;
		return is;
	}
	Student operator = (Student &st)
	{
		this->Name = st.Name, this->Surname = st.Surname, this->age = st.age, this->Group = st.Group;
		return *this;
	}
	bool operator < (Student &st)
	{
		if (Surname < st.Surname)return 1;
		return 0;
	}
	bool operator > (Student &st)
	{
		if (Surname > st.Surname)return 1;
		return 0;
	}
	bool operator == (Student &st)
	{
		if (Surname == st.Surname)return 1;
		return 0;
	}
	bool operator != (Student &st)
	{
		if (Surname != st.Surname)return 1;
		return 0;
	};
};
#pragma once 