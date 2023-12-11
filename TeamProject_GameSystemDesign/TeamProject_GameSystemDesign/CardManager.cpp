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

void CardManager::playerSelect() {// 주석처리한건 따로 함수로 만들던지 타일 영역과 상호작용 필요
    int playerSelection;
    int tilePosX, tilePosY;
    Card* selectedCard;
    cout << "몇 번째 카드를 선택할 것 인가요?(1or2)" << endl;
    cin >> playerSelection;
    cout << "타일의 위치를 선택하세요(x,y)" << endl;
    cin >> tilePosX >> tilePosY;

    if (playerSelection == 1) {
        selectedCard = hand.front();
        hand.pop_front();//핸드의 첫번째 카드 삭제
    }
    else {
        selectedCard = hand.back();
        hand.pop_back();//핸드의 두번째 카드 삭제
    }

    if (playerSelection == 1||playerSelection == 2) { //타일 파괴-> 캐스팅해서 구현
        //플레이어 턴 수 감소제거

        switch (selectedCard->getType()) {
        case 1:
            dynamic_cast<widthCard*>(selectedCard)->destroyTile(tilePosX, tilePosY);
            break;
        case 2:
            dynamic_cast<lengthCard*>(selectedCard)->destroyTile(tilePosX, tilePosY);
            break;
        case 3:
            dynamic_cast<dotCard*>(selectedCard)->destroyTile(tilePosX, tilePosY);
            break;
        case 4:
            dynamic_cast<xCard*>(selectedCard)->destroyTile(tilePosX, tilePosY);
            break;
        case 5:
            dynamic_cast<longWidthCard*>(selectedCard)->destroyTile(tilePosX, tilePosY);
            break;
        case 6:
            dynamic_cast<longLengthCard*>(selectedCard)->destroyTile(tilePosX, tilePosY);
            break;
        case 7:
            dynamic_cast<squareCard*>(selectedCard)->destroyTile(tilePosX, tilePosY);
            break;
        case 8:
            dynamic_cast<purificationCard*>(selectedCard)->destroyTile(tilePosX, tilePosY);
            break;
        case 9:
            dynamic_cast<crossCard*>(selectedCard)->destroyTile(tilePosX, tilePosY);
            break;
        case 10:
            dynamic_cast<purificationCrossCard*>(selectedCard)->destroyTile(tilePosX, tilePosY);
            break;
        case 11:
            dynamic_cast<upgradeSquareCard*>(selectedCard)->destroyTile(tilePosX, tilePosY);
            break;
        case 12:
            dynamic_cast<upgradeXCard*>(selectedCard)->destroyTile(tilePosX, tilePosY);
            break;
        case 13:
            dynamic_cast<upgradeCrossCard*>(selectedCard)->destroyTile(tilePosX, tilePosY);
            break;
        case 14:
            dynamic_cast<hellFireCard*>(selectedCard)->destroyTile(tilePosX, tilePosY);
            break;
        }
        hand.push_back(ready.front());
        ready.push(cards.front());
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
            cards.push(new widthCard(WIDTH_TYPE, "Width", true));
        }
        else if ((i>=5)&&(i < 10)) {
            cards.push(new lengthCard(LENGTH_TYPE, "Length", true));
        }
        else {
            cards.push(new dotCard(DOT_TYPE, "Dot", true));
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
    int nowstage;
    //stage정보 GameManager에서 받아온다는 가정
    switch (nowstage) {
    case 1: //x 3장 추가
        for (int i = 0; i < 3; i++) {
            cards.push(new xCard(X_TYPE, "X", true));
        }
        break;
    case 2://삭제권 0~3장 추가
        this->deleteNum += rand() % 4;
        break;
    case 3://square 3장 추가
        for (int i = 0; i < 3; i++) {
            cards.push(new squareCard(SQUARE_TYPE, "Square", true));
        }
    case 4:// purification 1장 추가
        cards.push(new purificationCard(PURIFICATION_TYPE, "Purification", true,true));
        break;
    case 5://longlength 1장 추가
        cards.push(new longLengthCard(LONG_LENGTH_TYPE, "Long Length", true));
        break;
    case 6://longwidth 1장 추가
        cards.push(new longWidthCard(LONG_WIDTH_TYPE, "Long Width", true));
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
            printf("%d. Type: %d, Name: %s\n", i + 1, tempDeck[i]->getType(), tempDeck[i]->getName().c_str());//tempDeck에 존재하는 카드 정보 모두 출력
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