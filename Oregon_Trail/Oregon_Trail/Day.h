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
	string temp;
	string weather;
	int time;
	Group* wagon;
public: //getters, setters, etc.
	static int days;
	int getFood() { return foodConsume; }
	string getTemp() { return temp; }
	string getWeather() { return weather; }
	void setWeather();
	void setTemp();
	void dayStatus();
	void eat();
	void travel();
	Day(Group* wagon);
};