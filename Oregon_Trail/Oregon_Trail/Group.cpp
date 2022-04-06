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
CharacterNode::CharacterNode(string name, int hunger, int thirst, int health) {
	this->setName(name);
	this->setHunger(hunger);
	this->setThirst(thirst);
	this->setHealth(health);
}

/*
* Function: Character stats
* displays all character stats in small block
*/
void CharacterNode::showStats() {
	cout << endl << "----------------------" << endl;
	cout << name << " stats:" << endl;
	cout << "Hunger level: " << hunger << endl;
	cout << "Thirst level: " << thirst << endl;
	cout << "Health: " << health << endl;
	cout << "----------------------" << endl;
}

/*
* Function: Group constructor
* creates group with an inital character and sets the head pointer, this starts
* the chain of the linked list.
*/
Group::Group() {
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
* first version of two overloaded functions, the first one (when passed no arguments) removes the last
* character of the list
*/
void Group::removeCharacter() {
	--size;
	CharacterNode* cursor = head;
	while (cursor->next != NULL) {
		cursor = cursor->next;
	}
	CharacterNode* tempPtr = cursor;
	cursor = cursor->prev;
	cursor->next = NULL;
	delete tempPtr;
}

/*
* Function: remove character
* second version of the two overloaded functions, this one takes an index argument and
* removes that character from the list. automatically deals with sealing up the 
* hole in the list.
* Counting starts at 0 just like an array
*/
void Group::removeCharacter(int index) {
	--size;
	CharacterNode* cursor = head;
	for (int i = 0; i < index; i++) {
		cursor = cursor->next;
	}
	CharacterNode* tempPtr = cursor;
	cursor->prev->next = cursor->next;
	cursor->next->prev = cursor->prev;
	delete tempPtr;
}

/*
* Function: group status
* display entire groups status in list format
*/
void Group::groupStatus() {
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