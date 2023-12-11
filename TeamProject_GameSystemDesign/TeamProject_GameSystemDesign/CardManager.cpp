#include "CardManager.h"
using namespace std;

CardManager::CardManager() { //스테이지 보상별 Player 생성
    this->deleteNum = 0; //삭제권 개수 0으로 초기화
    InitDeck(); // 카드 생성 -> 초기카드 가로 5 세로 5 점3
    shuffleCards(); //카드 섞기 까지 마무리
    for (int i = 0; i < 2; i++) {
        hand.push_back(cards.front());//핸드에 카드 추가
        cards.pop();//추가한 카드를 카드덱에서 삭제
    }
    for (int i = 0; i < 2; i++) {
        ready.push(cards.front());//레디에 카드추가
        cards.pop();//추가한 카드를 카드덱에서 삭제
    }
}

CardManager::~CardManager() {
    while (!cards.empty()) {
        delete cards.front();
        cards.pop();
    }
}
void CardManager::InitDeck() {
    for (int i = 0; i < 13; i++) { //초기 카드개수 13장
        if (i < 5) {
            cards.push(new WidthCard());
        }
        else if ((i >= 5) && (i < 10)) {
            cards.push(new LengthCard());
        }
        else {
            cards.push(new DotCard());
        }
    }
}

void CardManager::shuffleCards() {
    vector<Card*> tempQueue;
    while (!cards.empty()) {
        tempQueue.push_back(cards.front());
        cards.pop();
    }

    random_device rd;
    default_random_engine rng(rd());
    shuffle(tempQueue.begin(), tempQueue.end(), rng);

    for (auto card : tempQueue) {
        cards.push(card);
    }
}

void CardManager::rewardCard() {
    int nowstage = 0;
    //stage정보 GameManager에서 받아온다는 가정
    switch (nowstage) {
    case 1: //x 3장 추가
        for (int i = 0; i < 3; i++) {
            cards.push(new XCard());
        }
        break;
    case 2://삭제권 0~3장 추가
        this->deleteNum += rand() % 4;
        break;
    case 3://square 3장 추가
        for (int i = 0; i < 3; i++) {
            cards.push(new SquareCard());
        }
    case 4:// purification 1장 추가
        cards.push(new PurificationCard());
        break;
    case 5://longlength 1장 추가
        cards.push(new LongLengthCard());
        break;
    case 6://longwidth 1장 추가
        cards.push(new LongWidthCard());
        break;
    case 7://삭제권 0~3장 추가
        this->deleteNum += rand() % 4;
        break;
    case 8://삭제권 0~3장 추가
        this->deleteNum += rand() % 4;
        break;
    default:
        break;
    }
}

void CardManager::deleteCard() {//deck카드에서 삭제하기
    if (this->deleteNum > 0) {
        int deleteSelect; //iterator로 써야 될듯
        vector<Card*> tempDeck;
        while (!cards.empty()) {
            tempDeck.push_back(cards.front());
            cards.pop();
        }
        printf("삭제할 카드의 인덱스를 입력하세요 :\n");
        scanf("%d", &deleteSelect);
        this->deleteNum--; //주어진 삭제권 하나 사용
        while (true) {
            if (deleteSelect <= tempDeck.size()) {
                tempDeck.erase(tempDeck.begin() + deleteSelect - 1);
                break;
            }
            else {
                printf("올바른 번호를 입력하세요");
            }
        }
        for (auto card : tempDeck) {//나머지 카드 다시 넣기
            cards.push(card);
        }
    }
}