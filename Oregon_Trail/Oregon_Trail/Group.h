#pragma once

#include <iostream>
#include <string>

using namespace std;

class CharacterNode {
private:
	int hunger;
	int health;
	string name;
public:
	//Getters/Setters
	int getHunger() { return hunger; }
	int getHealth() { return health; }
	string getName() { return name; }
	void setHunger(int hunger) { this->hunger = hunger; }
	void setHealth(int health) { this->health = health; }
	void setName(string name) { this->name = name; }

	//Constructors
	CharacterNode(string name, int hunger = 0, int health = 100);

	//Display
	void showStats();


	//Node Pointers
	CharacterNode* next;
	CharacterNode* prev;
};

class Group {
protected:
	int size;
	double distance;
	int rations;
	int targetMiles;
public:
	CharacterNode* head;
	Group();
	void addCharacter();
	void removeCharacter(int index);
	void removeCharacter();
	int getRations() { return rations; }
	void setRations(int r) { rations = r; }
	CharacterNode* getCharacter(int index = 0);
	void groupStatus();
	int getSize() { return size; }
	double getDistance() { return distance; }
	void setDistance(double dist) { distance += dist; }
	int getTarget() { return targetMiles; }
	void checkDead();
};
