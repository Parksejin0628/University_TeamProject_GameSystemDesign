#pragma once

#include <iostream>
#include <string>
#include"ProgramBase.h"
#include"ScreenManager.h"
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
    virtual void destroyTile(int &x, int &y);
    virtual void checkArea();
};

class widthCard : public Card {
public:
    widthCard(CardType type, string name, bool isActive) : Card(type, name, isActive) {}
    void destroyTile(int &x, int &y);
    void checkArea();
    
};

class lengthCard : public Card {
public:
    lengthCard(CardType type, string name, bool isActive) : Card(type, name, isActive) {}
    void destroyTile(int& x, int& y);
    void checkArea();
};

class dotCard : public Card {
public:
    dotCard(CardType type, string name, bool isActive) : Card(type, name, isActive) {}
    void destroyTile(int& x, int& y);
    void checkArea();
};

class xCard : public Card {
public:
    xCard(CardType type, string name, bool isActive) : Card(type, name, isActive) {}
    void destroyTile(int& x, int& y);
    void checkArea();
};

class longWidthCard : public Card {
public:
    longWidthCard(CardType type, string name, bool isActive) : Card(type, name, isActive) {}
    void destroyTile(int& x, int& y);
    void checkArea();
};

class longLengthCard : public Card {
public:
    longLengthCard(CardType type, string name, bool isActive) : Card(type, name, isActive) {}
    void destroyTile(int& x, int& y);
    void checkArea();
};

class squareCard : public Card {
public:
    squareCard(CardType type, string name, bool isActive) : Card(type, name, isActive) {}
    void destroyTile(int& x, int& y);
    void checkArea();
};

class purificationCard :public Card {
public:
    bool isClear;
    purificationCard(CardType type, string name, bool isActive, bool isClear) : Card(type, name, isActive),isClear(isClear){}
    void destroyTile(int& x, int& y);
    void checkArea();
};

class crossCard : public Card {
public:
    crossCard(CardType type, string name, bool isActive) : Card(type, name, isActive) {}
    void destroyTile(int& x, int& y);
    void checkArea();
};

class purificationCrossCard : public purificationCard {
public:
    purificationCrossCard(CardType type, string name, bool isActive,bool isClear) : purificationCard(type, name, isActive,isClear) {}
    void destroyTile(int& x, int& y);
    void checkArea();
};

class upgradeSquareCard : public Card {
public:
    upgradeSquareCard(CardType type, string name, bool isActive) : Card(type, name, isActive) {}
    void destroyTile(int& x, int& y);
    void checkArea();
};

class upgradeXCard : public Card {
public:
    upgradeXCard(CardType type, string name, bool isActive) : Card(type, name, isActive) {}
    void destroyTile(int& x, int& y);
    void checkArea();
};
class upgradeCrossCard : public Card {
public:
    upgradeCrossCard(CardType type, string name, bool isActive) : Card(type, name, isActive) {}
    void destroyTile(int& x, int& y);
    void checkArea();
};
class hellFireCard : public Card {
public:
    hellFireCard(CardType type, string name, bool isActive) : Card(type, name, isActive) {}
    void destroyTile(int& x, int& y);
    void checkArea();
};