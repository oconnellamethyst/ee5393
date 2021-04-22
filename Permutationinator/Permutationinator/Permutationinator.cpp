// Permutationinator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Logics.h"
#include "Permutationinator.h"

int main()
{
	cout << "start the nand" << endl;
	nand(0, 0); std::cout << "DONE" << endl << endl;
	nand(0, 1); std::cout << "DONE" << endl << endl;
	nand(1, 0); std::cout << "DONE" << endl << endl;
	nand(1, 1); std::cout << "DONE" << endl << endl;

	cout << "start the mystery funct" << endl;
	mysteryfunct(0, 0);
	mysteryfunct(0, 1);
	mysteryfunct(1, 0);
	mysteryfunct(1, 1);

	/*//I am way too lazy/efficient to write i/o for the command line rn
	Logics x = 0;
	Logics y = 0;
	Logics z = 0;
	
	//(((x ^ y)* z)^ x);
	!y;
std::cout << "DONE1" << endl << endl;

	x = 0;
	y = 0;
	z = 1;

	//(((x ^ y) * z) ^ x);
	y^ z;
std::cout << "DONE2" << endl << endl;

	x = 0;
	y = 1;
	z = 0;

	//(((x ^ y) * z) ^ x);
	y^ z;
std::cout << "DONE3" << endl << endl;

	x = 0;
	y = 1;
	z = 1;

	//(((x ^ y) * z) ^ x);
	y^ z;
	/*
std::cout << "DONE4" << endl << endl;

	x = 1;
	y = 0;
	z = 0;

	//(((x ^ y) * z) ^ x);
	x^ y;
std::cout << "DONE5" << endl << endl;

	x = 1;
	y = 0;
	z = 1;

	//(((x ^ y) * z) ^ x);
	x^ y;
std::cout << "DONE6" << endl << endl;

	x = 1;
	y = 1;
	z = 0;

	//(((x ^ y) * z) ^ x);
	x^ y;
std::cout << "DONE7" << endl << endl;

	x = 1;
	y = 1;
	z = 1;

	//(((x ^ y) * z) ^ x);
	x^ y;
std::cout << "DONE8" << endl << endl; */
	while(1) {};
};

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
