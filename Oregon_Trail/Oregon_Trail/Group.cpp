#pragma once

#include <iostream>
#include <string>
#include "Group.h"
#include "Utility.h"

using namespace std;

/*
* Function: Character node constructor, 
* just creates character with base values and name.
*/
Character::Character(string name, int hunger, int health) {
	this->setName(name);
	this->setHunger(hunger);
	this->setHealth(health);
}

/*
* Function: Character stats
* displays all character stats in small block
*/
void Character::showStats() {
	cout << endl << name << " stats:" << endl;
	cout << "Hunger level: " << hunger << endl;
	cout << "Health: " << health << endl << endl;
}

/*
* Function: Group constructor
* creates group with an inital character and sets the head pointer, this starts
* the chain of the linked list.
*/
Group::Group() {
	targetMiles = 2800;
	rations = 50;
	distance = 0;
	people.push_back(Character(getString("Enter Name: ")));
}

/*
* Function: group status
* display entire groups status in list format
*/
void Group::groupStatus() {
	cout << endl << "------- Group Status -------" << endl;
	cout << "Miles done: " << distance << endl;
	cout << "Miles left: " << targetMiles - distance << endl;
	cout << "";
	
	for (int i = 0; i < people.size(); i++) {
		cout << endl << people[i].getName() << " stats:" << endl;
		cout << "Hunger: " << people[i].getHunger() << endl;
		cout << "Health: " << people[i].getHealth() << endl;
	}

	cout << endl << "----------------------------" << endl;
}


void Group::checkDead() {
	if (people.size() <= 0) {
		cout << "Everyone is dead." << endl;
		cout << "Truth is, the game was rigged from the start." << endl;
	}
	else {
		for (int i = 0; i < people.size(); i++) {
			if (people[i].getHealth() <= 0 || people[i].getHunger() >= 100) {
				cout << people[i].getName() << " died" << endl;
				people.erase(people.begin() + i);
			}
		}
	}
}