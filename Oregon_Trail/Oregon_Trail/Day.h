#pragma once

#include <iostream>
#include <string>
#include "Group.h"
using namespace std;

class Day
{
protected:
	int foodConsume;
	int restCounter;
	string temps[3] = { "Cold", "Normal", "Hot" };
	string weathers[3] = { "Calm", "Gusty", "Stormy"};
	int temp;
	int weather;
	int Time;
	Group* wagon;
public: //getters, setters, etc.
	static int days;
	int getFood() { return foodConsume; }
	string getTemp() { return temps[temp]; }
	string getWeather() { return weathers[weather]; }
	void setWeather();
	void setTemp();
	void eat();
	void travel();
	void hunt();
	void rest();
	void action();
	Day(Group* wagon);
};