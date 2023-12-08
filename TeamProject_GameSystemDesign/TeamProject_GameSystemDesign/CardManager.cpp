#include "CardManager.h"


using namespace std;

CardManager::CardManager(int stage) { //스테이지 보상별 Player 생성
    
    setNumCards(INITIAL_PLAYER_DECK_NUMBER + (stage - 1) * CARDS_ADDED_PER_STAGE);

    for (int i = 0; i < numCards; i++) {
        if (i < 5) {
            cards.push(new Card(WIDTH_TYPE, "width", true));
        }
        else if (i < 10) {
            cards.push(new Card(LENGTH_TYPE, "length", true));
        }
        else if (stage >= 2 && i < 13) {
            cards.push(new Card(X_TYPE, "X", true));
        }
        else if (stage >= 4 && i < 16) {
            cards.push(new Card(SQUARE_TYPE, "square", true));
        }
        else if (stage >= 5 && i < 19) {
            cards.push(new Card(PURIFICATION_TYPE, "purification", true));
        }
        else if (stage >= 6 && i < 22) {
            cards.push(new Card(LONG_LENGTH_TYPE, "long length", true));
        }
        else if (stage >= 7 && i < 25) {
            cards.push(new Card(LONG_WIDTH_TYPE, "long width", true));
        }
        else {
            cards.push(new Card(DOT_TYPE, "dotType", true));
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
        hand.push_back(cards.front());
        cards.pop();
    }
    for (int i = 0; i < 2; i++) {
        ready.push(cards.front());
        cards.pop();
    }

}

Card CardManager::playerSelect() {// 주석처리한건 따로 함수로 만들던지 타일 영역과 상호작용 필요
    int playerSelection;
    //int cardPosX, cardPosY;
    Card selectedCard;
    cout << "몇 번째 카드를 선택할 것 인가요?(1or2)" << endl;
    cin >> playerSelection;
    //cout << "어느 위치에 카드를 낼 것 인가요?(x와y좌표를 입력하시오)" << endl; //타일과 상호작용 필요
    //cin >> cardPosX>>cardPosY;

    if (playerSelection == 1||playerSelection == 2) {
        this->playerTurn--;

        if (playerSelection == 1) {
            selectedCard = *hand.front();
            hand.pop_front();
        }
        else {
            selectedCard = *hand.back();
            hand.pop_back();

            hand.push_back(ready.front());
            ready.pop();
            ready.push(cards.front());
            cards.pop();
            return selectedCard;
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