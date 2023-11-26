#pragma once

#include <iostream>
#include <string>
#include"constants.h"

using namespace std;

class Card {
    int type;       // 카드 타입
    int index;      // 카드의 위치 (왼쪽 기준)
    string name;    // 카드 이름
    bool isActive;  // 카드 활성 상태

public:
    Card(int type, string name, bool isActive);
    int getType();
    int getIndex();
    string getName();
    void setIndex(int idx);
    void setActive(bool active);
    Card operator+(Card& other);
    Card createMergedCard(Card& other);
};