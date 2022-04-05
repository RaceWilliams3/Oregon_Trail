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

void Day::setFood(int food)
{
	if (Day::getWeather() == "Calm Winds")
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
		time = 0;
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
	CharacterNode* cursor = wagon->head;
	for (int i = 0; i < wagon->getSize(); i++) {
		cursor->showStats();
		cursor->setHunger((cursor->getHunger() - rat*10));
		wagon->setRations(wagon->getRations() - rat);
		if (cursor->getHunger() < 0) {
			cursor->setHunger(0);
		}
		cursor = cursor->next;
		
	}
	cout << "Current Group Rations: " << wagon->getRations() << endl;
	wagon->groupStatus();
}

void Day::travel() {
	
}