#include <iostream>
#include <string>
#include "Group.h"
#include "Utility.h"

using namespace std;

int main() {
	//Just testing of the functions
	Group wagon;
	wagon.addCharacter();
	wagon.addCharacter();
	wagon.groupStatus();
	wagon.removeCharacter(1);
	cout << "Deleted: " << endl;
	wagon.groupStatus();

	return 0;
}