#pragma once

#include <iostream>
#include <string>
#include "Group.h"
#include "Utility.h"

using namespace std;


CharacterNode::CharacterNode(string name, int hunger, int thirst, int health) {
	this->setName(name);
	this->setHunger(hunger);
	this->setThirst(thirst);
	this->setHealth(health);
}

void CharacterNode::showStats() {
	cout << endl << "----------------------" << endl;
	cout << name << " stats:" << endl;
	cout << "Hunger level: " << hunger << endl;
	cout << "Thirst level: " << thirst << endl;
	cout << "Health: " << health << endl;
	cout << "----------------------" << endl;
}


Group::Group() {
	this->head = NULL;
	this->head = new CharacterNode(getString());
	head->next = NULL;
	head->prev = NULL;

}

void Group::addCharacter() {
	CharacterNode* newNode = new CharacterNode(getString());
	CharacterNode* cursor = head;
	while (cursor->next != NULL) {
		cursor = cursor->next;
	}
	cursor->next = newNode;
	newNode->next = NULL;
	newNode->prev = cursor;
}

void Group::removeCharacter() {
	CharacterNode* cursor = head;
	while (cursor->next != NULL) {
		cursor = cursor->next;
	}
	CharacterNode* tempPtr = cursor;
	cursor = cursor->prev;
	cursor->next = NULL;
	delete tempPtr;
}

void Group::groupStatus() {
	CharacterNode* cursor = head;
	while (cursor->next != NULL) {
		cursor->showStats();
		cursor = cursor->next;
	}
	cursor->showStats();
}

CharacterNode* Group::getCharacter(int index) {
	CharacterNode* cursor = head;
	for (int i = 0; i < index; i++) {
		cursor = cursor->next;
	}
	return cursor;
}