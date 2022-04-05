#include <iostream>
#include <string>
#include "Group.h"
#include "Utility.h"
#include "Title.h"
#include "Day.h"

using namespace std;

int main() {
	srand(time(NULL));

	titleScreen();

	//Just testing of the functions
	Group wagon;
	
	cout << "---------" << endl;
	try {
			Day* day1 = new Day(&wagon);
			day1->dayStatus();

	}
	catch (const char* x) {
		cout << "ERROR: " << x << endl;
	}

	return 0;
}