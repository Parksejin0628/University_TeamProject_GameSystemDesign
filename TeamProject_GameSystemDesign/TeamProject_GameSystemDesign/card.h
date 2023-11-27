#pragma once

#include <iostream>
#include <string>
#include"constants.h"

using namespace std;

class Card {
    int type;       // 카드 타입
    string name;    // 카드 이름
    bool isActive;  // 카드 활성 상태

public:
    Card(int type, string name, bool isActive);
    int getType();
    string getName();
    void setActive(bool active);
    Card operator+(Card& other);
    Card createMergedCard(Card& other);
};

class Purification :public Card {
    bool purification;//정화 가능 여부
public:
    void purify();
};