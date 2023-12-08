#include "Card.h"
#include <cstdlib>

Card::Card()
{
    type = 0;
    name = "unnamed";
    isActive = false;

}

Card::Card(int type, string name, bool isActive) {
    this->type = type;
    this->name = name;
    this->isActive = isActive;
}

int Card::getType(){
    return this->type;
}

string Card::getName(){
    return this->name;
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
    //가로 + 세로 = 십자가 카드
    if ((type == WIDTH_TYPE && other.type == LENGTH_TYPE) || (type == LENGTH_TYPE && other.type == WIDTH_TYPE)) {
        return Card(CROSS_TYPE, "Cross", true);
    }
    //정화 + 정화 = 정화 십자가 카드
    else if ((type == PURIFICATION_TYPE && other.type == PURIFICATION_TYPE)) {
        return Card(PURIFICATION_CROSS_TYPE, "Purification Cross", true);
    }
    //네모 + 네모 = 100% 3*3 네모 카드
    else if ((type == SQUARE_TYPE && other.type == SQUARE_TYPE)) {
        return Card(UPGRADE_SQUARE_TYPE, "Upgrade Square", true);
    }
    //X + X = 7*7 X 카드
    else if ((type == X_TYPE && other.type == X_TYPE)) {
        return Card(UPGRADE_X_TYPE, "Upgrade X", true);
    }
    //긴가로 + 긴세로 = 긴 가로 세로 카드
    else if ((type == LONG_LENGTH_TYPE && other.type == LONG_WIDTH_TYPE) || (type == LONG_WIDTH_TYPE && other.type == LONG_LENGTH_TYPE)) {
        return Card(UPGRADE_CROSS_TYPE, "Upgrade Cross", true);
    }
    //네모 + 십자가 = 업화 카드
    else if ((type == CROSS_TYPE && other.type == UPGRADE_SQUARE_TYPE) || (type == UPGRADE_SQUARE_TYPE && other.type == CROSS_TYPE)) {
        return Card(HELLFIRE_TYPE, "Hell Fire", true);
    }
}

void Purification::purify() {
    this->purification = true;
}