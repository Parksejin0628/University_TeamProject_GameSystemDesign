#include "card.h"
#include <cstdlib>

Card::Card(int type, int cardUpgrade, string name) {
    this->type = type;
    this->upgradeStep = cardUpgrade;
    this->name = name;
}

int Card::getType() {
    return this->type;
}

int Card::getUpgradeStep() {
    return this->upgradeStep;
}

int Card::index() {
    return this->index;
}


string Card::getName() {
    return this->name;
}

void Card::setIndex(int&idx) {
    this->index = idx;
}
Card Card::operator+(Card& other) { //기획안에 맞춰 수정할 예정
    if (this->type == other.getType()) {
        int upgradedStep = this->upgradeStep + other.upgradeStep;
        return Card(this->type, upgradedStep, this->name);
    }
    else {
        return *this;
    }
}