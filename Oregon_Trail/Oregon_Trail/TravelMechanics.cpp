/*
* Matthew Shepard
*
* Travel Mechanics:
* Keeps track of days passed, distance travelled, food/water consumption.
* Days passed: after actions have been taken
* distance travelled: 30-50mi a day, randomly chosen
* food/water consume: more water on hot day, equal parts on a normal day, more food on a cold day.
*/
#include <iostream>
#include <string>
#include "Group.h"
#include "Day.h"
using namespace std;

Day day(Group wagon)
{
	Day day;
	double dist = 0;

	while (wagon.getSize() > 0) //group of people > 0
	{
		//checking weather conditions
		day.setDistWeather();

		//Distance Travelled (between 15-50mi, depending on weather2)
		if (day.getDistWeather() == "Calm Winds")
		{
			(dist += (40.0 + (rand() % (11))));
			wagon.setDistance(dist);
		}
		else if (day.getDistWeather() == "Gusty")
		{
			dist += (25.0 + (rand() % (11)));
			wagon.setDistance(dist);
		}
		else
		{
			dist += (15.0 + (rand() % (11)));
			wagon.setDistance(dist);
		}
	}
	return day;
}

