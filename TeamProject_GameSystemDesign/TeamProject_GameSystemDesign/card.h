#pragma once

#include <iostream>
#include <string>
#include"ProgramBase.h"

using namespace std;

class Card {
protected:
    CardType type;       // 카드 타입
    vector<Area> area;
public:
    Card(CardType type);
    vector<Area>& GetArea();
    bool CreateMergedCard(Card& other, Card& result);
};

class WidthCard : public Card {
public:

    WidthCard();
};

class LengthCard : public Card {
public:
    LengthCard();
};

class DotCard : public Card {
public:
    DotCard();
};

class XCard : public Card {
public:
    XCard();
};

class LongWidthCard : public Card {
public:
    LongWidthCard();
};

class LongLengthCard : public Card {
public:
    LongLengthCard();
};

class SquareCard : public Card {
public:
    SquareCard();
};

class PurificationCard :public Card {
public:
    bool isClear;
    PurificationCard();
};

class CrossCard : public Card {
public:
    CrossCard();
};

class PurificationCrossCard : public PurificationCard {
public:
    PurificationCrossCard();
};

class UpgradeSquareCard : public Card {
public:
    UpgradeSquareCard();
};

class UpgradeXCard : public Card {
public:
    UpgradeXCard();
};
class UpgradeCrossCard : public Card {
public:
    UpgradeCrossCard();
};
class HellFireCard : public Card {
public:
    HellFireCard();
};