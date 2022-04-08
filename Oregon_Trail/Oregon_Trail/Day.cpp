#pragma once

#include <iostream>
#include <string>
#include "Day.h"
#include "Group.h";
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
	cout << "Weather: " << weather << endl;
	cout << "Temp: " << temp << endl;
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

	cout << "------------------DEBUG----------------" << endl;

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
	cout << "------------------DEBUG----------------" << endl;
}

void Day::travel() 
{
	srand(time(NULL));

}

void Day::action()
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

		cout << "Eat, Hunt, Travel or Rest?: ";
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
			//Day::hunt();
		}
		else if (userInput == "travel" || userInput == "Travel")
		{
			Day::travel();
		}
		else if (userInput == "rest" || userInput == "Rest")
		{
			//Day::rest();
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