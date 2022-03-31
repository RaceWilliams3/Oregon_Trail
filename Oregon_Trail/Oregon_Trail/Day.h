#pragma once

#include <iostream>
#include <string>
using namespace std;

class Day
{
protected:
	int foodConsume;
	int waterConsume;
	int restCounter;
	string foodWeather;
	string distWeather;
public: //getters, setters, etc.
	int getFood() { return foodConsume; }
	int getWater() { return waterConsume; }
	string getFoodWeather() { return foodWeather; }
	string getDistWeather() { return distWeather; }
	void setFood(int food);
	void setWater(int water);
	string setDistWeather();
	string setFoodWeather();
};