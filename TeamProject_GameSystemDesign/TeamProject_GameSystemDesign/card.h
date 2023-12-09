#pragma once

#include <iostream>
#include <string>
#include"constants.h"

using namespace std;

class Card {
    CardType type;       // 카드 타입
    string name;    // 카드 이름
    bool isActive;  // 카드 활성 상태 -> 카드합치기 할때 사용함
public:
    Card(CardType type, string name, bool isActive);
    CardType getType();
    string getName();
    void setActive(bool active);
    Card operator+(Card& other);
    Card createMergedCard(Card& other);
    virtual void destroyTile(int &x, int &y) = 0;
};

class widthCard : public Card {
public:
    void destroyTile(int &x, int &y);
};

class lengthCard : public Card {
public:
    void destroyTile(int& x, int& y);
};

class dotCard : public Card {
public:
    void destroyTile(int& x, int& y);
};

class xCard : public Card {
public:
    void destroyTile(int& x, int& y);
};

class longWidthCard : public Card {
public:
    void destroyTile(int& x, int& y);
};

class longLengthCard : public Card {
public:
    void destroyTile(int& x, int& y);
};

class squareCard : public Card {
public:
    void destroyTile(int& x, int& y);
};

class purificationCard :public Card {
public:
    bool isClear;
    purificationCard(int type, string name, bool isActive, bool isClear);
    void destroyTile(int& x, int& y);
};

class crossCard : public Card {
public:
    void destroyTile(int& x, int& y);
};

class purificationCrossCard : public purificationCard {
public:
    void destroyTile(int& x, int& y);
};

class upgradeSquareCard : public Card {
public:
    void destroyTile(int& x, int& y);
};

class upgradeXCard : public Card {
public:
    void destroyTile(int& x, int& y);
};
class upgradeCrossCard : public Card {
public:
    void destroyTile(int& x, int& y);
};
class hellFireCard : public Card {
public:
    void destroyTile(int& x, int& y);
};