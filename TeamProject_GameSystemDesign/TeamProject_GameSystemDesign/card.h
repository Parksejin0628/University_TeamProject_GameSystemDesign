#pragma once

#include <iostream>
#include <string>
#include"constants.h"

using namespace std;

class Card {
    int type;//매크로
    int index;//카드의 위치( 왼쪽 기준 )
    int upgradeStep;//업그레이드 단계
    string name;//카드 이름

public:
    Card(int type, int upgradeStep = 1, string name);
    int getType();
    int getIndex();
    int getUpgradeStep();
    string getName();
    void setIndex(int &idx);
    Card operator+(Card& other);//기획안에 맞춰 수정 필요
};

