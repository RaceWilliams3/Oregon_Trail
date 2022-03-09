#include <iostream>
#include <string>
#include "Group.h"
#include "Utility.h"

using namespace std;

int main() {
	Group wagon;
	wagon.addCharacter();
	wagon.addCharacter();
	wagon.groupStatus();
	wagon.removeCharacter();
	cout << "Deleted: " << endl;
	wagon.groupStatus();

	return 0;
}