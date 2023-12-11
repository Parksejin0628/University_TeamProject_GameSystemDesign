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

void CardManager::playerSelect(int playerSelection) {// 주석처리한건 따로 함수로 만들던지 타일 영역과 상호작용 필요
    Card *selectedCard;

    if (playerSelection == 1) {
        selectedCard = hand.front();
        hand.pop_front();//핸드의 첫번째 카드 삭제
    }
    else {
        selectedCard = hand.back();
        hand.pop_back();//핸드의 두번째 카드 삭제
    }

    if (playerSelection == 1 || playerSelection == 2) { 

        switch (selectedCard->getType()) {
        case 1:
            delete selectedCard;
            selectedCard = new WidthCard();
            break;
        case 2:
            delete selectedCard;
            selectedCard = new LengthCard();
            break;
        case 3:
            delete selectedCard;
            selectedCard = new DotCard();
            break;
        case 4:
            delete selectedCard;
            selectedCard = new XCard();
            break;
        case 5:
            delete selectedCard;
            selectedCard = new LongWidthCard();
            break;
        case 6:
            delete selectedCard;
            selectedCard = new LongLengthCard();
            break;
        case 7:
            delete selectedCard;
            selectedCard = new SquareCard();
            break;
        case 8:
            delete selectedCard;
            selectedCard = new PurificationCard(PURIFICATION_TYPE);
            break;
        case 9:
            delete selectedCard;
            selectedCard = new CrossCard();
            break;
        case 10:
            delete selectedCard;
            selectedCard = new PurificationCrossCard();
            break;
        case 11:
            delete selectedCard;
            selectedCard = new UpgradeSquareCard();
            break;
        case 12:
            delete selectedCard;
            selectedCard = new UpgradeXCard();
            break;
        case 13:
            delete selectedCard;
            selectedCard = new UpgradeCrossCard();
            break;
        case 14:
            delete selectedCard;
            selectedCard = new HellFireCard();
            break;
        }
        //사용 한 이후
        tomb.push(selectedCard);//사용한 카드 tomb에 추가
        hand.push_back(ready.front());//ready의 맨 앞카드를 가져옴
        ready.pop();//ready의 맨앞 삭제
        if (cards.size() > 0) {
            ready.push(cards.front());//cards의 맨앞 카드 가져옴
            cards.pop();//card의 맨앞 삭제
        }
        else {
            shuffleTomb();
            ready.push(cards.front());//레디에 카드추가
            cards.pop();//추가한 카드를 카드덱에서 삭제
        }
        
        
        
    }
    else {
        cout << "잘 못된 입력입니다." << endl;
        exit(1);
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
    cout << "error" << endl;
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

void CardManager::rewardCard(int nowstage) {
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
        cards.push(new PurificationCard(PURIFICATION_TYPE,true));
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

        for (int i = 0; i < tempDeck.size(); i++) {
            printf("%d. Type: %d\n", i + 1, tempDeck[i]->getType());//tempDeck에 존재하는 카드 정보 모두 출력
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

void CardManager::shuffleTomb() {
    vector<Card*> tempQueue;
    while (!tomb.empty()) {
        tempQueue.push_back(tomb.front());
        tomb.pop();
    }

    random_device rd;
    default_random_engine rng(rd());
    shuffle(tempQueue.begin(), tempQueue.end(), rng);

    for (auto card : tempQueue) {
        cards.push(card);
    }
}