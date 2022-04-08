#include <iostream>
#include <string>
#include "Group.h"
#include "Utility.h"
#include "Title.h"
#include "Day.h"

using namespace std;

int main() {
	srand(time(NULL));
	int userInput;

	titleScreen();

	//Just testing of the functions
	cout << "How many characters are in the wagon?: ";
	cin >> userInput;
	while (!cin)
	{
		cout << "ERROR: Invalid input, please try again: ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> userInput;
	}
	Group wagon;

	try {
		Day* day = new Day(&wagon);
		for (int i = 1; i < userInput; ++i)
		{
			wagon.addCharacter();
			wagon.getCharacter(i)->setHunger(100);
		}
		wagon.setRations(100);
		day->dayStatus();

		day->action();
	}
	catch (const char* x) {
		cout << "ERROR: " << x << endl;
	}


	return 0;
}