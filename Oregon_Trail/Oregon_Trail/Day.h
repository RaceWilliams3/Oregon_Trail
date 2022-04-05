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
	int time;
	Group* wagon;
public: //getters, setters, etc.
	static int days;
	int getFood() { return foodConsume; }
	int getWater() { return waterConsume; }
	string getTemp() { return temp; }
	string getWeather() { return weather; }
	void setFood(int food);
	void setWater(int water);
	void setWeather();
	void setTemp();
	void dayStatus();
	void eat();
	void travel();
	Day(Group* wagon);
};