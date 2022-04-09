#pragma once

#include <iostream>
#include <string>
#include "Utility.h"

using namespace std;

/*
* Function: get string
* Condenses getting user input for a string with error checking into one function
*/
string getString(const char* request) {
	string temp;
	cout << request;
	cin >> temp;
	while (!cin) {
		cout << "ERROR: Bad input try again: ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> temp;
	}
	return temp;
}

/*
template <class t>
t randRange(t low, t high) {
	high++;
	return (rand() % (high - low)) + low;
}
*/

int randRange(int low, int high) {
	high++;
	return (rand() % (high - low)) + low;
}

//double randRange(double low, double high) {
//	high++;
//	return (rand() % (high - low)) + low;
//}