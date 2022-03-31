#include <iostream>
#include <string>
#include "Day.h"
using namespace std;



string Day::setFoodWeather()
{
	int weather = 0;

	srand(time(NULL));
	weather = rand() % 3;
	// switch statement for weather
	switch (weather)
	{
	case 0:
		Day::foodWeather = "Hot";
		break;
	case 1:
		Day::foodWeather = "Cold";
		break;
	case 2:
		Day::foodWeather = "Normal";
		break;
	}
	return Day::foodWeather;
}

string Day::setDistWeather()
{
	int weather = 0;

	weather = rand() % 3;

	switch (weather)
	{
	case 0:
		Day::distWeather = "Calm Winds";
		break;
	case 1:
		Day::distWeather = "Gusty";
		break;
	case 2:
		Day::distWeather = "Stormy";
		break;
	}
	return Day::distWeather;
}

void Day::setFood(int food)
{
	if (Day::getFoodWeather() == "Calm Winds")
	{
		Day::foodConsume = 
	}
}

void Day::setWater(int water)
{

}