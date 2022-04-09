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

	double dist = 0;
	if (wagon->getSize() > 0) //group of people > 0
	{
		setTemp();
		setWeather();
		Time = 0;
	}
	else {
		throw ("Empty Group");
		delete this;
	}
}

void Day::dayStatus() {
	cout << "Day " << days << endl;
	cout << "Weather: " << weathers[weather] << endl;
	cout << "Temp: " << temps[temp] << endl;
	wagon->groupStatus();
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

	if (rat > (wagon->getRations()/wagon->getSize())) {
		cout << "Greater number that current rations entered, using the max amount instead." << endl;
		rat = (wagon->getRations() / wagon->getSize());
	}
	for (int i = 0; i < wagon->getSize(); i++) {
		CharacterNode* psn = wagon->getCharacter(i);
		psn->setHunger((psn->getHunger() - rat * 10));
		if (psn->getHunger() < 0) {
			psn->setHunger(0);
		}
		wagon->setRations(wagon->getRations() - rat);
	}

	cout << "Current Group Rations: " << wagon->getRations() << endl;
	wagon->groupStatus();
}

void Day::travel() 
{
	int tDistance = 0;
	switch (weather) {
	case(0):
		tDistance = randRange(50, 100);
		wagon->setDistance(wagon->getDistance() + tDistance);
		break;
	case(1):
		tDistance = randRange(30, 60);
		wagon->setDistance(wagon->getDistance() + tDistance);
		break;
	case(2):
		tDistance = randRange(10, 20);
		wagon->setDistance(wagon->getDistance() + tDistance);
		break;
	}
	cout << "You went " << tDistance << " miles." << endl;
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
	for (int i = 0; i < wagon->getSize(); i++) {
		CharacterNode* psn = wagon->getCharacter(i);
		psn->setHunger(psn->getHunger() + randRange(low, high));
	}

	for (int i = 0; i < wagon->getSize(); i++) {
		injuryChance(wagon->getCharacter(i), 10, 5, 10,"traveling");
	}


	wagon->groupStatus();
}

void Day::hunt() {
	bool goodName = false;
	CharacterNode* hunter = wagon->head;
	goodName = false;
	while (goodName == false) {
		string tName = getString("Who do you want to send hunting? ");
		for (int i = 0; i < wagon->getSize(); i++) {
			if (tName == wagon->getCharacter(i)->getName()) {
				hunter = wagon->getCharacter(i);
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

void Day::action(Group* wagon)
{
	string userInput;
	int dayTime;
	Day::Time = 0;

	while (Day::Time < 2)
	{
		cout << "----------" << endl;
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
			//Day::rest();
		}
		else if (userInput == "status" || userInput == "Status")
		{
			wagon->groupStatus();
		}
		else
		{
			cout << "Invalid Input, please try again." << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin >> userInput;
		}
	}
}