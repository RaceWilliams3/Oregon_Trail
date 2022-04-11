#pragma once

#include <iostream>
#include <string>
#include "Group.h"

using namespace std;

string getString(const char* request);
int getInt(const char* request);

int randRange(int low, int high);

void injuryChance(CharacterNode* psn, int chance, int lowDamage, int highDamage,string injury = " ");

