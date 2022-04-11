#include <iostream>
#include <string>
#include "Group.h"
#include "Utility.h"
#include "Title.h"
#include "Day.h"

using namespace std;

int main() {

	srand(time(NULL));
	Group wagon;
	wagon.addCharacter();
	wagon.addCharacter();
	wagon.addCharacter();
	wagon.addCharacter();
	wagon.groupStatus();
	wagon.getCharacter(1)->setHealth(0);
	wagon.getCharacter(2)->setHealth(0);
	wagon.getCharacter(4)->setHealth(0);
	wagon.groupStatus();
	cout << "DEBUG" << endl;
	wagon.checkDead();
	wagon.groupStatus();
	wagon.checkDead();
	wagon.groupStatus();


	return 0;
}


int bonk() {
	//Seed Random one at the begining of the game
	srand(time(NULL));
	titleScreen();

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
	for (int i = 1; i < userInput; ++i)
	{
		wagon.addCharacter();
	}
	while (wagon.getDistance() < wagon.getTarget()) {
		try {
			Day* day = new Day(&wagon);
			day->action();
		}
		catch (const char* x) {
			cout << "ERROR: " << x << endl;
		}
	}
	
	return 0;
}