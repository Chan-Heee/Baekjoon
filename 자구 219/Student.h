#pragma once
#include <string>
using namespace std;

class Student {
public:

	int id;
	int tArrival;
	string gender;
	Student(int i = 0, int tArr = 0, string gen = " ")
		:id(i), tArrival(tArr), gender(gen) {}
};
