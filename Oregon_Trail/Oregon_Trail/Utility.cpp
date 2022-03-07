#include <iostream>
#include <string>

using namespace std;

string* getString() {
	string* temp;
	cin >> *temp;
	while (!cin) {
		cout << "ERROR - Bad input try again: ";
		cin.ignore(INT_MAX, '\n');
		cin.clear();
		cin >> *temp;
	}
	return temp;
}