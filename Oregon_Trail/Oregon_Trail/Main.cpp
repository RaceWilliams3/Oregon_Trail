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
	cout << "The second charcter namne is: " << wagon.getCharacter(1)->getName() << endl;
	return 0;
}