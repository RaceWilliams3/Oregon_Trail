#pragma once

#include <iostream>
#include <string>
#include "Day.h"
#include "Group.h"
#include "Utility.h"
using namespace std;


int Day::days = 0;

void Day::setTemp()
{
	temp = randRange(0, 2);
}

void Day::setWeather()
{
	weather = randRange(0, 2);
}

Day::Day(Group* wagon) {
	days++;
	this->wagon = wagon;
	cout << "Day " << days << endl;
	cout << wagon->getTarget() - wagon->getDistance() << " miles left" << endl;
	double dist = 0;
	if (wagon->people.size() > 0) //group of people > 0
	{
		setTemp();
		setWeather();
		Time = 0;
	}
	else {
		throw ("Empty Group");
		delete this;
	}
	cout << "Weather: " << weathers[weather] << endl;
	cout << "Temp: " << temps[temp] << endl;
}

void Day::eat() {
	cout << "Current Group Rations: " << wagon->getRations() << endl;
	cout << "How many Rations per person do you want to eat: ";
	int rat = 0;
	cin >> rat;
	while (!cin) {
		cout << "ERROR: Bad Input Try Again: ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> rat;
	}

	if (rat > (wagon->getRations()/wagon->people.size())) {
		cout << "Greater number that current rations entered, using the max amount instead." << endl;
		rat = (wagon->getRations() / wagon->people.size());
	}
	for (int i = 0; i < wagon->people.size(); i++) {
		Character* psn = &wagon->people[i];
		psn->setHunger((psn->getHunger() - rat * 10));
		if (psn->getHunger() < 0) {
			psn->setHunger(0);
		}
		wagon->setRations(wagon->getRations() - rat);
	}

	cout << "Current Group Rations: " << wagon->getRations() << endl;
}

void Day::travel() 
{
	int tDistance = 0;
	switch (weather) {
	case(0):
		tDistance = randRange(25, 50);
		break;
	case(1):
		tDistance = randRange(15, 30);
		break;
	case(2):
		tDistance = randRange(5, 10);
		break;
	}
	cout << "tDistance: " << tDistance << endl;
	cout << "distance before adding tDistance: " << wagon->getDistance() << endl;
	wagon->addDistance(tDistance);
	cout << "You went " << tDistance << " miles." << endl;
	cout << "Distance: " << wagon->getDistance() << endl;
	int low = 0;
	int high = 0;
	switch (temp) {
	case(0):
		low = 10;
		high = 20;
		break;
	case(1):
		low = 5;
		high = 15;
		break;
	case(2):
		low = 15;
		high = 30;
		break;
	}
	for (int i = 0; i < wagon->people.size(); i++) {
		Character* psn = &wagon->people[i];
		psn->setHunger(psn->getHunger() + randRange(low, high));
	}

	for (int i = 0; i < wagon->people.size(); i++) {
		injuryChance(&wagon->people[i], 10, 5, 10, "traveling");
	}
}

void Day::hunt() {
	bool goodName = false;
	Character* hunter = &wagon->people[0];
	goodName = false;
	while (goodName == false) {
		string tName = getString("Who do you want to send hunting? ");
		for (int i = 0; i < wagon->people.size(); i++) {
			if (tName == wagon->people[i].getName()) {
				hunter = &wagon->people[i];
				goodName = true;
			}
		}
		if (goodName == false) {
			cout << "That person is not in the group, try again. " << endl;
		}
	}
	injuryChance(hunter, 50, 10, 50, "hunting");
	if (randRange(0, 100) < 75) {
		int food = randRange(2, 10);
		int tRations = food * randRange(4, 6);
		cout << hunter->getName() << " was able to get " << food << " lbs of food!" << endl;
		cout << "they made " << tRations << " rations" << endl;
		wagon->setRations(wagon->getRations() + tRations);

	}
	else {
		cout << hunter->getName() << " was not able to get any food." << endl;
	}
}

void Day::rest() {
	for (int i = 0; i < wagon->people.size(); i++) {
		Character* psn = &wagon->people[i];
		psn->setHealth(psn->getHealth() + randRange(15, 50));
		if (psn->getHealth() > 100) {
			psn->setHealth(100);
		}		
		psn->setHunger(psn->getHunger() + randRange(2,5));
	}
}

void Day::action()
{
	string userInput;
	int dayTime;
	Day::Time = 0;

	while (Day::Time < 2)
	{
		dayTime = Day::Time % 2;
		switch (dayTime)
		{
		case 0:
			cout << "MORNING: " << endl;
			++Day::Time;
			break;
		case 1:
			cout << "AFTERNOON: " << endl;
			++Day::Time;
			break;
		}

		cout << "Eat, Hunt, Travel, Rest or Status?: ";
		cin >> userInput;
		while (!cin)
		{
			cout << "ERROR: Not a string." << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin >> userInput;
		}

		if (userInput == "eat" || userInput == "Eat")
		{
			Day::eat();
		}
		else if (userInput == "hunt" || userInput == "Hunt")
		{
			Day::hunt();
		}
		else if (userInput == "travel" || userInput == "Travel")
		{
			Day::travel();
		}
		else if (userInput == "rest" || userInput == "Rest")
		{
			Day::rest();
		}
		else
		{
			cout << "Invalid Input, please try again." << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin >> userInput;
		}
	}
	wagon->checkDead();
	wagon->groupStatus();
}