#pragma once

#include "card.h"
#include <algorithm>
#include <random>
#include <vector>
#include <queue>
#include <list>

class CardManager {
    int deleteNum;//삭제권 개수
    queue<Card*> cards;  // 덱을 나타내는 큐
    list<Card*> hand;       // 손에 든 카드를 나타내는 리스트
    queue<Card*> ready;      // 사용 가능한 카드를 나타내는 큐
public:
    CardManager();//삭제권 0으로 초기화, 카드 초기화, 핸드 초기화, 다음에올 카드들 초기화
    ~CardManager();
    void InitDeck();//덱 초기화
    void playerSelect(); //유저가 카드 선택하는 함수, 선택하면 카드는 cards에서 delete
    void shuffleCards();//카드 섞기
    void rewardCard();//스테이지 정보받아서 cards에 push하기
    void deleteCard();//삭제권
};
