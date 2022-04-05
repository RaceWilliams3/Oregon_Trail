#include <iostream>
#include <string>
#include "Group.h"
#include "Utility.h"
#include "Day.h"

using namespace std;

int main() {
	srand(time(NULL));

	//Just testing of the functions
	Group wagon;
	
	cout << "---------" << endl;
	try {
			Day* day = new Day(&wagon);
			wagon.addCharacter();
			wagon.getCharacter(0)->setHunger(100);
			wagon.getCharacter(1)->setHunger(100);
			wagon.setRations(100);
			day->dayStatus();
			day->eat();

	}
	catch (const char* x) {
		cout << "ERROR: " << x << endl;
	}

	return 0;
}