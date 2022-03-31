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

int day(Group wagon)
{
	int day = 0;
	
	while (wagon.getSize() > 0) //group of people > 0
	{
		srand(time(NULL));
		day = rand() % 7;
		//switch statement for weather

		//Distance Travelled (randon between 30-50mi)

		//food/water consumption

		//increment day
	}
	return day;
}