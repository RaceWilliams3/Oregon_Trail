#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Character {
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
	Character(string name, int hunger = 0, int health = 100);

	//Display
	void showStats();
};

class Group {
protected:
	double distance;
	int rations;
	int targetMiles;
public:
	vector<Character> people;
	Group();
	int getRations() { return rations; }
	void setRations(int r) { rations = r; }
	void groupStatus();
	double getDistance() { return distance; }
	void addDistance(double dist) { distance += dist; }
	int getTarget() { return targetMiles; }
	void checkDead();
};
