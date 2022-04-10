#include <iostream>
#include <string>
#include "Group.h"
#include "Utility.h"
#include "Title.h"
#include "Day.h"

using namespace std;

int main() {
	//Seed Random one at the begining of the game
	srand(time(NULL));
	titleScreen();

	int targetMiles = 2800;

	int userInput;
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
	while (wagon.getDistance() < targetMiles) {
		try {
			Day* day = new Day(&wagon);
			for (int i = 1; i < userInput; ++i)
			{
				wagon.addCharacter();
			}
			day->dayStatus();

			day->action();
		}
		catch (const char* x) {
			cout << "ERROR: " << x << endl;
		}
	}
	


	return 0;
}