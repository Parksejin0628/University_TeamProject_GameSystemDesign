#include "player.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Player::Player() {//Init에서 cards배열중에 2개 뽑는거 구현
    for (int i = 0; i < 5; i++) {
        cards[i] = new Card(WIDTH_TYPE, 1, "widthType");
    }
    for (int i = 5; i < 10; i++) {
        cards[i] = new Card(LENGTH_TYPE, 1, "lengthType");
    }
    for (int i = 10; i < PLAYER_DECK_NUMBER; i++) {
        cards[i] = new Card(DOT_TYPE, 1, "dotType");
    }
    this->playerTurn = PLAYER_STAGE1_TURN;//플레이어가 스테이지 1을 조작한다고 가정, 조건문 써서 스테이지 구현 예정
}

Card Player::playerSelect() {
    int playerSelection, cardPosX, cardPosY;
    cout << "몇 번째 카드를 선택할 것 인가요?" << endl;
    cin >> playerSelection;
    cout << "어느 위치에 카드를 낼 것 인가요?(x와y좌표를 입력하시오)" << endl;
    cin >> cardPosX>>cardPosY;

    if (cardPosX >= 1 &&cardPosY>=1 && playerSelection <= PLAYER_DECK_NUMBER) { //유효한 입력
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