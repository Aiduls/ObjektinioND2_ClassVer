// OOP3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Vector.h"

int main()
{
	//std::cout << gruz.size();
	int n = 0, tempMark;

	Vector<int> test;
	test.push_back(5);

	test.assign(10, 5);
	for (int i : test) {
		std::cout << i << " ";
	}
}
