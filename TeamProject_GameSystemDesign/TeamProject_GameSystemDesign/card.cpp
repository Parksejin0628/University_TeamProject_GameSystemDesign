#include "card.h"
#include <cstdlib>

Card::Card(int type, string name, bool isActive) {
    this->type = type;
    this->name = name;
    this->isActive = isActive;
}

int Card::getType(){
    return this->type;
}

int Card::getIndex(){
    return this->index;
}

string Card::getName(){
    return this->name;
}

void Card::setIndex(int& idx) {
    this->index = idx;
}

void Card::setActive(bool active) {
    this->isActive = active;
}

Card Card::operator+(Card& other){
    if (!isActive && !other.isActive) {
        Card result = createMergedCard(other);

        // 관련된 카드의 활성 상태를 업데이트
        this->setActive(false);
        result.setActive(true);

        return result;
    }
    exit(1);
}

Card Card::createMergedCard(Card& other) {
    if ((type == WIDTH_TYPE && other.type == LENGTH_TYPE) || (type == LENGTH_TYPE && other.type == WIDTH_TYPE)) {
        return Card(CROSS_TYPE, "Cross", true);
    }
    else if ((type == PURIFICATION_TYPE && other.type == PURIFICATION_TYPE)) {
        return Card(PURIFICATION_CROSS_TYPE, "Purification Cross", true);
    }
    else if ((type == SQUARE_TYPE && other.type == SQUARE_TYPE)) {
        return Card(UPGRADE_SQUARE_TYPE, "Upgrade Square", true);
    }
    else if ((type == X_TYPE && other.type == X_TYPE)) {
        return Card(UPGRADE_X_TYPE, "Upgrade X", true);
    }
    else if ((type == LONG_LENGTH_TYPE && other.type == LONG_WIDTH_TYPE) || (type == LONG_WIDTH_TYPE && other.type == LONG_LENGTH_TYPE)) {
        return Card(UPGRADE_CROSS_TYPE, "Upgrade Cross", true);
    }
    else if ((type == CROSS_TYPE && other.type == UPGRADE_SQUARE_TYPE) || (type == UPGRADE_SQUARE_TYPE && other.type == CROSS_TYPE)) {
        return Card(HELLFIRE_TYPE, "Hell Fire", true);
    }
}