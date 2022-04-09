#pragma once

#include <iostream>
#include <string>
#include "Utility.h"
#include "Group.h"

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


int getInt(const char* request) {
	int temp;
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

int randRange(int low, int high) {
	high++;
	return (rand() % (high - low)) + low;
}

void injuryChance(CharacterNode* psn, int chance, int lowDamage, int highDamage,string injury) {
	if (randRange(0, 100) > (100-chance)) {
		cout << psn->getName() << " got hurt " << injury << endl;
		psn->setHealth(psn->getHealth() - randRange(lowDamage, highDamage));
	}
}