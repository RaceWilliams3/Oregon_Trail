#include <iostream>
#include <string>
#include "Group.h"
#include "Utility.cpp"

using namespace std;


Character::Character(string name, int hunger, int thirst, int health) {
	this->setName(name);
	this->setHunger(hunger);
	this->setThirst(thirst);
	this->setHealth(health);
}

Character::Character() {

}

void Character::showStats() {
	cout << name << " stats:" << endl;
	cout << "Hunger level: " << hunger << endl;
	cout << "Thirst level: " << thirst << endl;
	cout << "Health: " << health << endl;
}


Group::Group(int size) {
	int i = 0;
	for (i = 0; i < size; i++) {
		this->peop	le[i] = getString();
	}
}