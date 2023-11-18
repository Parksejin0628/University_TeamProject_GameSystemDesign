#pragma once

#include <iostream>
#include <string>
#include"constants.h"

using namespace std;

class Card {
    int cost;
    int type;
    int upgradeStep;
    string name;

public:
    Card(int cost, int type, int upgradeStep = 1, string name);
    int getCost();
    int getType();
    string getName();
    Card operator+(Card& other);
};

class SpecialCard : public Card {
    string skill;

public:
    string getSkill();
};
