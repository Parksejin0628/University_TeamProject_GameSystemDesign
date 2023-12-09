#include "CardManager.h"


using namespace std;

CardManager::CardManager(int stage) { //스테이지 보상별 Player 생성
    
    setNumCards(INITIAL_PLAYER_DECK_NUMBER + (stage - 1) * CARDS_ADDED_PER_STAGE);

    for (int i = 0; i < numCards; i++) {
        if (i < 5) {
            cards.push(new widthCard(WIDTH_TYPE, "width", true));
        }
        else if (i < 10) {
            cards.push(new lengthCard(LENGTH_TYPE, "length", true));
        }
        else if (stage >= 2 && i < 13) {
            cards.push(new xCard(X_TYPE, "X", true));
        }
        else if (stage >= 4 && i < 16) {
            cards.push(new squareCard(SQUARE_TYPE, "square", true));
        }
        else if (stage >= 5 && i < 19) {
            cards.push(new purificationCard(PURIFICATION_TYPE, "purification", true));
        }
        else if (stage >= 6 && i < 22) {
            cards.push(new longLengthCard(LONG_LENGTH_TYPE, "long length", true));
        }
        else if (stage >= 7 && i < 25) {
            cards.push(new longWidthCard(LONG_WIDTH_TYPE, "long width", true));
        }
        else {
            cards.push(new dotCard(DOT_TYPE, "dotType", true));
        }
    }
    switch (stage) {
    case 1:
        this->playerTurn = PLAYER_STAGE1_TURN;
        break;
    case 2:
        this->playerTurn = PLAYER_STAGE2_TURN;
        break;
    case 3:
        this->playerTurn = PLAYER_STAGE3_TURN;
        break;
    case 4:
        this->playerTurn = PLAYER_STAGE4_TURN;
        break;
    case 5:
        this->playerTurn = PLAYER_STAGE5_TURN;
        break;
    case 6:
        this->playerTurn = PLAYER_STAGE6_TURN;
        break;
    case 7:
        this->playerTurn = PLAYER_STAGE7_TURN;
        break;
    case 8:
        this->playerTurn = PLAYER_STAGE8_TURN;
        break;
    case 9:
        this->playerTurn = PLAYER_STAGE9_TURN;
        break;

    default:
        this->playerTurn = PLAYER_STAGE1_TURN;
        break;
    }
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
    Card selectedCard;
    cout << "몇 번째 카드를 선택할 것 인가요?(1or2)" << endl;
    cin >> playerSelection;
    cout << "타일의 위치를 선택하세요(x,y)" << endl;
    cin >> tilePosX >> tilePosY;

    if (playerSelection == 1||playerSelection == 2) { //타일 파괴-> 캐스팅해서 구현
        this->playerTurn--;

        switch (selectedCard.getType()) {
        case 1:
            dynamic_cast<widthCard*>selectedCard.destroyTile(tilePosX, tilePosY);
            break;
        case 2:
            dynamic_cast<lengthCard*>selectedCard.destroyTile(tilePosX, tilePosY);
            break;
        case 3:
            dynamic_cast<dotCard*>selectedCard.destroyTile(tilePosX, tilePosY);
            break;
        case 4:
            dynamic_cast<xCard*>selectedCard.destroyTile(tilePosX, tilePosY);
            break;
        case 5:
            dynamic_cast<longWidthCard*>selectedCard.destroyTile(tilePosX, tilePosY);
            break;
        case 6:
            dynamic_cast<longLengthCard*>selectedCard.destroyTile(tilePosX, tilePosY);
            break;
        case 7:
            dynamic_cast<squareCard*>selectedCard.destroyTile(tilePosX, tilePosY);
            break;
        case 8:
            dynamic_cast<purificationCard*>selectedCard.destroyTile(tilePosX, tilePosY);
            break;
        case 9:
            dynamic_cast<crossCard*>selectedCard.destroyTile(tilePosX, tilePosY);
            break;
        case 10:
            dynamic_cast<purificationCrossCard*>selectedCard.destroyTile(tilePosX, tilePosY);
            break;
        case 11:
            dynamic_cast<upgradeSquareCard*>selectedCard.destroyTile(tilePosX, tilePosY);
            break;
        case 12:
            dynamic_cast<upgradeXCard*>selectedCard.destroyTile(tilePosX, tilePosY);
            break;
        case 13:
            dynamic_cast<upgradeCrossCard*>selectedCard.destroyTile(tilePosX, tilePosY);
            break;
        case 14:
            dynamic_cast<hellFireCard*>selectedCard.destroyTile(tilePosX, tilePosY);
            break;
        }

        if (playerSelection == 1) {
            selectedCard = hand.front();
            hand.pop_front();//핸드의 첫번째 카드 삭제
        }
        else {
            selectedCard = hand.back();
            hand.pop_back();//핸드의 두번째 카드 삭제
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

void CardManager::setNumCards(int num) {
    this->numCards = num;
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