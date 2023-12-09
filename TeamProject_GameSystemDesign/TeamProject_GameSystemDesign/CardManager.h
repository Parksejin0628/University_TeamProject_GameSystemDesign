#pragma once

#include "card.h"
#include <algorithm>
#include <random>
#include <vector>
#include <queue>
#include <list>

class CardManager { 
    queue<Card*> cards;  // 덱을 나타내는 큐
    list<Card*> hand;       // 손에 든 카드를 나타내는 리스트
    queue<Card*> ready;      // 사용 가능한 카드를 나타내는 큐
    int playerTurn;
    int numCards; //플레이어가 가지고 있는 카드 덱의 숫자
    
public: 
    CardManager(int stage);//스테이지 정보 필요 -> 덱에 포함되는 카드수 + 종류
    ~CardManager();
    void playerSelect(); //유저가 카드 선택하는 함수, 선택하면 카드는 cards에서 delete
    void shuffleCards();//카드 섞기
    void setNumCards(int num);//카드 개수 설정
};
