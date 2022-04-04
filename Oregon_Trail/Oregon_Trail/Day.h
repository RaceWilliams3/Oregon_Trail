#pragma once

#include <iostream>
#include <string>
#include "Group.h"
using namespace std;

class Day
{
protected:
	int foodConsume;
	int waterConsume;
	int restCounter;
	string temp;
	string weather;
	string time;
	Group* wagon;
public: //getters, setters, etc.
	static int days;
	int getFood() { return foodConsume; }
	int getWater() { return waterConsume; }
	string getFoodWeather() { return temp; }
	string getDistWeather() { return weather; }
	void setFood(int food);
	void setWater(int water);
	void setWeather();
	void setTemp();
	void dayStatus();
	Day(Group* wagon);
};