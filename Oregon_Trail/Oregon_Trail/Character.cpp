

#include <iostream>
#include <string>
#include "Character.h"

using namespace std;


Character::Character(string name, int hunger, int thirst, int health) {
	this->setName(name);
	this->setHunger(hunger);
	this->setThirst(thirst);
	this->setHealth(health);
}

void Character::showStats() {
	cout << name << " stats:" << endl;
	cout << "Hunger level: " << hunger << endl;
	cout << "Thirst level: " << thirst << endl;
	cout << "Health: " << health << endl;
}