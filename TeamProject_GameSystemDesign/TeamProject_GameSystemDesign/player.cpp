#include "player.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Player::Player() {
    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < PLAYER_DECK_NUMBER; i++) {
        int cost = NORMAL_CARD_COST;
        int type = rand() % 5 + 1;
        string name;

        if (type == SQURE_SHAPE_TYPE)
            name = "square";
        else if (type == STRAIGHT_TYPE)
            name = "straightShape";
        else if (type == T_SHPAE_TYPE)
            name = "tShape";
        else if (type == Z_SHAPE_TYPE)
            name = "zShape";
        else if (type == L_SHAPE_TYPE)
            name = "lShape";

        int upgradeStep = 1;
        cards[i] = new Card(cost, type, upgradeStep, name);
    }

    this->userCost = USER_COST;
    this->playerTurn = PLAYER_TURN;
}

Card Player::playerSelect() {
    int playerSelection, cardPos;
    cout << "몇 번째 카드를 선택할 것 인가요?" << endl;
    cin >> playerSelection;
    cout << "어느 위치의 카드를 낼 것 인가요?" << endl;
    cin >> cardPos;

    if (cardPos >= 1 && cardPos <= PLAYER_DECK_NUMBER) {
        this->playerTurn--;
        delete this->cards[cardPos - 1];
        this->cards[cardPos - 1] = nullptr;
    }
    else {
        cout << "잘 못된 입력입니다." << endl;
    }
}

Player::~Player() {
    for (int i = 0; i < PLAYER_DECK_NUMBER; i++) {
        delete cards[i];
        cards[i] = nullptr;
    }
}