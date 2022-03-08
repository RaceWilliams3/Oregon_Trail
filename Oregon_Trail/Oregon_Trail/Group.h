#pragma once

#include <iostream>
#include <string>

using namespace std;

class CharacterNode {
private:
	int hunger;
	int thirst;
	int health;
	string name;
public:
	//Getters/Setters
	int getHunger() { return hunger; }
	int getThirst() { return thirst; }
	int getHealth() { return health; }
	string getName() { return name; }
	void setHunger(int hunger) { this->hunger = hunger; }
	void setThirst(int thirst) { this->thirst = thirst; }
	void setHealth(int health) { this->health = health; }
	void setName(string name) { this->name = name; }

	//Constructors
	CharacterNode(string name, int hunger = 0, int thirst = 0, int health = 100);

	//Display
	void showStats();

	//Node Pointers
	CharacterNode* next;
	CharacterNode* prev;
};

class Group {
protected:
	CharacterNode* head;
public:
	Group();
	void addCharacter();
	CharacterNode* getCharacter(int index = 0);
	void groupStatus();

};
