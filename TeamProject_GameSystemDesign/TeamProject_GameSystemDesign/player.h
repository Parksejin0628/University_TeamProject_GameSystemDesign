#pragma once

#include "card.h"

class Player { 
    Card* cards[PLAYER_DECK_NUMBER]; //유저가 가지고 있는 카드
    int userCost;//유저가 초기 가지고 있는 코스트
    int playerTurn;

public:
    Player();
    ~Player();
    Card playerSelect(); //유저가 카드 선택하는 함수, 선택하면 카드 delete
};