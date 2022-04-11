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
CharacterNode::CharacterNode(string name, int hunger, int health) {
	this->setName(name);
	this->setHunger(hunger);
	this->setHealth(health);
}

/*
* Function: Character stats
* displays all character stats in small block
*/
void CharacterNode::showStats() {
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
	string name[20];
	size = 1;
	distance = 0;
	this->head = new CharacterNode(getString("Enter Name: "));
	head->next = NULL;
	head->prev = NULL;

}

/*
* Function: add character
* adds a new character with user selected name and default stats at  the end of list
*/
void Group::addCharacter() {
	++size;
	CharacterNode* newNode = new CharacterNode(getString("Enter Name: "));
	CharacterNode* cursor = head;
	while (cursor->next != NULL) {
		cursor = cursor->next;
	}
	cursor->next = newNode;
	newNode->next = NULL;
	newNode->prev = cursor;
}

/*
* Function: remove character
* this one takes an index argument and removes that character from the list. 
* automatically deals with sealing up the 
* hole in the list.
* Counting starts at 0 just like an array
*/


void d(int message) {
	cout << "DEBUG: " << message << " success" << endl;
}

void Group::removeCharacter(int index) {
	--size;
	d(1);
	CharacterNode* c = getCharacter(index);
	d(2);
	if (c->prev != NULL) {
		c->prev->next = c->next;
	}
	d(3);
	if (c->next != NULL) {
		c->next->prev = c->prev;
	}
	d(4);
	free(c);
	d(5);
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
	CharacterNode* cursor = head;
	while (cursor->next != NULL) {
		cursor->showStats();
		cursor = cursor->next;
	}
	cursor->showStats();
}

/*
* Function: get Character
* allows access to individual character stats and functions, index works the same as
* an array.
*/
CharacterNode* Group::getCharacter(int index) {
	CharacterNode* cursor = head;
	for (int i = 0; i < index; i++) {
		cursor = cursor->next;
	}
	return cursor;
}

void Group::checkDead() {
	if (size <= 0) {
		cout << "Everyone is dead." << endl;
		cout << "You failed" << endl;
	}
	else {
		/*for (int i = 0; i < size; i++) {
			cout << "iteration: " << i << endl << "checking: " << getCharacter(i)->getName()  << endl;
			if (getCharacter(i)->getHealth() <= 0 || getCharacter(i)->getHunger() >= 100) {
				cout << getCharacter(i)->getName() << " died" << endl;
				removeCharacter(i);
			}
			else {
				cout << getCharacter(i)->getName() << " is good" << endl;
			}
		}*/

		CharacterNode* cursor = head;
		int i = 0;
		while (cursor != NULL) {
			cout << "iteration: " << i << endl << "checking: " << cursor->getName() << endl;
			if (cursor->getHealth() <= 0 || cursor->getHunger() >= 100) {
				cout << cursor->getName() << " died" << endl;
				
				removeCharacter(i);
				i++;
			}
			else {
				cout << cursor->getName() << " is good" << endl;
				i++;
			}
			cursor = cursor->next;
			
		}
	}
}