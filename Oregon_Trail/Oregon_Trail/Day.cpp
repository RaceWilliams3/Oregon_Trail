#pragma once

#include <iostream>
#include <string>
#include "Day.h"
using namespace std;


int Day::days = 0;


void Day::setTemp()
{
	string h = "Hot";
	string n = "Normal";
	string c = "Cold";
	int num = 0;
	num = rand() % 3;
	// switch statement for weather
	switch (num)
	{
	case 0:
		temp = h;
		break;
	case 1:
		temp = n;
		break;
	case 2:
		temp = c;
		break;
	}
}

void Day::setWeather()
{
	string w = "Calm Winds";
	string g = "Gusty";
	string s = "Stormy";
	int num = 0;

	num = rand() % 3;

	switch (num)
	{
	case 0:
		this->weather = w;
		break;
	case 1:
		this->weather = g;
		break;
	case 2:
		this->weather = s;
		break;
	}
}

void Day::setFood(int food)
{
	if (Day::getFoodWeather() == "Calm Winds")
	{
		Day::foodConsume = 0;
	}
}

void Day::setWater(int water)
{
	
}

Day::Day(Group* wagon) {
	days++;
	this->wagon = wagon;

	double dist = 0;
	if (wagon->getSize() > 0) //group of people > 0
	{
		setTemp();
		setWeather();
	}
	else {
		throw ("Empty Group");
		delete this;
	}
}

void Day::dayStatus() {
	cout << "Day " << days << endl;
	cout << "Weather: " << weather << endl;
	cout << "Temp: " << temp << endl;
	wagon->groupStatus();
}


/* use for the travel function 
//checking weather conditions
		this->setDistWeather();

		//Distance Travelled (between 15-50mi, depending on weather2)
		if (this->getDistWeather() == "Calm Winds")
		{
			(dist += (40.0 + (rand() % (11))));
			wagon->setDistance(dist);
		}
		else if (this->getDistWeather() == "Gusty")
		{
			dist += (25.0 + (rand() % (11)));
			wagon->setDistance(dist);
		}
		else
		{
			dist += (15.0 + (rand() % (11)));
			wagon->setDistance(dist);
		}



*/