#pragma once

#include <iostream>
#include <string>

using namespace std;

class Character {
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
	Character(string name, int hunger = 0, int thirst = 0, int health = 100);

	//Display
	void showStats();
};