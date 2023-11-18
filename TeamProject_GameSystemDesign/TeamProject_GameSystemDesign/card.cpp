#include "card.h"
#include <cstdlib>

Card::Card(int cost, int type, int cardUpgrade, string name) {
    this->cost = cost;
    this->type = type;
    this->upgradeStep = cardUpgrade;
    this->name = name;
}

int Card::getCost() {
    return this->cost;
}

int Card::getType() {
    return this->type;
}

string Card::getName() {
    return this->name;
}

Card Card::operator+(Card& other) {
    if (this->type == other.getType()) {
        int upgradedStep = this->upgradeStep + other.upgradeStep;
        return Card(this->cost, this->type, upgradedStep, this->name);
    }
    else {
        return *this;
    }
}

string SpecialCard::getSkill() {
    // 특수카드 스킬 기획 필요
    return "";
}