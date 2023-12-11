#include "card.h"
#include <cstdlib>

Card::Card(CardType type, string name, bool isActive) {
    this->type = type;
    this->name = name;
}

CardType Card::getType(){
    return this->type;
}

string Card::getName(){
    return this->name;
}

void Card::setActive(bool active) {
    this->isActive = true;
}

void Card::destroyTile(int &x, int &y) {

}
void Card::checkArea() {

}
Card Card::operator+(Card& other){
    if (!isActive && !other.isActive) {
        Card resultCard = createMergedCard(other);

        // 관련된 카드의 활성 상태를 업데이트
        this->setActive(false);
        resultCard.setActive(true);

        return resultCard;
    }
    exit(1);
}

Card Card::createMergedCard(Card& other) {
    if ((type == WIDTH_TYPE && other.type == LENGTH_TYPE) || (type == LENGTH_TYPE && other.type == WIDTH_TYPE)) {
        return crossCard(CROSS_TYPE, "Cross", true);
    }
    else if ((type == PURIFICATION_TYPE && other.type == PURIFICATION_TYPE)) {
        return purificationCard(PURIFICATION_CROSS_TYPE, "Purification Cross", true, true);
    }
    else if ((type == SQUARE_TYPE && other.type == SQUARE_TYPE)) {
        return upgradeSquareCard(UPGRADE_SQUARE_TYPE, "Upgrade Square", true);
    }
    else if ((type == X_TYPE && other.type == X_TYPE)) {
        return upgradeXCard(UPGRADE_X_TYPE, "Upgrade X", true);
    }
    else if ((type == LONG_LENGTH_TYPE && other.type == LONG_WIDTH_TYPE) || (type == LONG_WIDTH_TYPE && other.type == LONG_LENGTH_TYPE)) {
        return upgradeCrossCard(UPGRADE_CROSS_TYPE, "Upgrade Cross", true);
    }
    else if ((type == CROSS_TYPE && other.type == UPGRADE_SQUARE_TYPE) || (type == UPGRADE_SQUARE_TYPE && other.type == CROSS_TYPE)) {
        return hellFireCard(HELLFIRE_TYPE, "Hell Fire", true);
    }
    else
        exit(1);
}
//widthCard::widthCard(CardType type, string name, bool isActive) : Card(type, name, isActive) {
//    type = WIDTH_TYPE;
//    name = "Width";
//    isActive = true;
//}
void widthCard::destroyTile(int& x, int& y) {
    checkArea();
    //bool isNormal = Interact(x, y);//일반타일 인지 아닌지 확인
    //if (isNormal) {
    //    tileMap[x][y].isActive = false;
    //}
    //bool isNormalLeft = Interact(x, y - 1);//왼쪽타일 확인
    //if (isNormalLeft && (rand() % 2 == 0)) {
    //    tileMap[x][y - 1].isActive = false;
    //}

    //bool isNormalRight = Interact(x, y + 1);//오른쪽 타일 확인
    //if (isNormalRight && (rand() % 2 == 0)) {
    //    tileMap[x][y + 1].isActive = false;
    //}
    ////의문인게 왼쪽카드가 없을수도 있지 않나? 즉 null일 수도 있잖아 이건 물어보는 걸로...
}

void widthCard::checkArea() {
    vector<Position>area;
    area.push_back({ 0,0 });
    area.push_back({ 1,0 });
    area.push_back({ -1,0 });
}
//lengthCard::lengthCard(CardType type, string name, bool isActive) : Card(type, name, isActive) {
//    type = LENGTH_TYPE;
//    name = "Length";
//    isActive = true;
//}

void lengthCard::checkArea() {
    vector<Position>area;
    area.push_back({ 0,0 });
    area.push_back({ 0,1 });
    area.push_back({ 0,-1 });
}
void lengthCard::destroyTile(int& x, int& y) {
    //bool isNormal = Interact(x,y);//일반카드 인지 아닌지 확인
    //if (isNormal) {
    //    tileMap[x][y].isActive = false;
    //}
    //bool isNormalUp = Interact(x-1, y);//위쪽카드 확인
    //if (isNormalUp && (rand() % 2 == 0)) {
    //    tileMap[x-1][y].isActive = false;
    //}

    //bool isNormalDown = Interact(x+1, y);//아래쪽 카드 확인
    //if (isNormalDown && (rand() % 2 == 0)) {
    //    tileMap[x+1][y].isActive = false;
    //}
}
//dotCard::dotCard(CardType type, string name, bool isActive) : Card(type, name, isActive) {
//    type = DOT_TYPE;
//    name = "Dot";
//    isActive = true;
//}

void dotCard::checkArea() {
    vector<Position>area;
    area.push_back({ 0,0 });
}

void dotCard::destroyTile(int& x, int& y) {
    //bool isNormal = Interact(x, y);//일반카드 인지 아닌지 확인
    //if (isNormal) {
    //    tileMap[x][y].isActive = false;
    //}
}
//xCard::xCard(CardType type, string name, bool isActive) : Card(type, name, isActive) {
//    type = X_TYPE;
//    name = "X";
//    isActive = true;
//}
void xCard::checkArea() {
    vector<Position>area;
    area.push_back({ 0,0 });
    area.push_back({ 1,1 });
    area.push_back({ 1,-1 });
    area.push_back({ -1,1 });
    area.push_back({ -1,-1 });
}
void xCard::destroyTile(int& x, int& y) {
    //bool isNormal = Interact(x, y);//일반카드 인지 아닌지 확인
    //if (isNormal) {
    //    tileMap[x][y].isActive = false;
    //}
    //bool isNormalAboveLeftDiagonal = Interact(x - 1, y - 1);//대각선 카드들 검사
    //if (isNormalAboveLeftDiagonal && (rand() % 2 == 0)) {
    //    tileMap[x - 1][y - 1].isActive = false;
    //}

    //bool isNormalAboveRightDiagonal = Interact(x - 1, y + 1);
    //if (isNormalAboveRightDiagonal && (rand() % 2 == 0)) {
    //    tileMap[x - 1][y + 1].isActive = false;
    //}

    //bool isNormalBelowLeftDiagonal = Interact(x + 1, y - 1);
    //if (isNormalBelowLeftDiagonal && (rand() % 2 == 0)) {
    //    tileMap[x + 1][y - 1].isActive = false;
    //}

    //bool isNormalBelowRightDiagonal = Interact(x + 1, y + 1);
    //if (isNormalBelowRightDiagonal && (rand() % 2 == 0)) {
    //    tileMap[x + 1][y + 1].isActive = false;
    //}
}
//longWidthCard::longWidthCard(CardType type, string name, bool isActive) : Card(type, name, isActive) {
//    type = LONG_WIDTH_TYPE;
//    name = "Long Width";
//    isActive = true;
//}
void longWidthCard::checkArea() {
    vector<Position>area;
    for (SHORT i = -4; i < 5; i++) {
        area.push_back({ i,0 });
    }
}
void longWidthCard::destroyTile(int& x, int& y) {
    //bool isNormal = Interact(x, y);//일반카드 인지 아닌지 확인
    //if (isNormal) {
    //    tileMap[x][y].isActive = false;
    //}
    //srand(time(0)); // 

    //// 선택된 타일 (선택된 타일)

    //for (int i = 0; i < tileMap[x].size(); ++i) {//y에 대해 검사하는 건데 맞는지 모르겠다.
    //    if (i != y) {
    //        // 각 타일에 대한 isNormal 확인
    //        bool isNormal = Interact(x, i);

    //        if (isNormal) {
    //            // 선택된 지점으로부터의 거리 계산
    //            int distance = std::abs(y - i);

    //            // 거리에 따라 파괴 확률 조절
    //            int destructionProbability = 100 - distance * 15;

    //            // 파괴 확률을 [0, 100] 범위 내로 조절
    //            destructionProbability = std::max(0, std::min(100, destructionProbability));


    //            // 난수가 파괴 확률 이내인지 확인하고 파괴 여부 결정
    //            if (rand()%100 <= destructionProbability) {
    //                tileMap[x][i].isActive = false;
    //            }
    //        }
    //    }
    //}
}
//longLengthCard::longLengthCard(CardType type, string name, bool isActive) : Card(type, name, isActive) {
//    type = LONG_LENGTH_TYPE;
//    name = "Width";
//    isActive = true;
//}

void longLengthCard::checkArea() {
    vector<Position>area;
    for (SHORT i = -4; i < 5; i++) {
        area.push_back({ 0,i });
    }
}
void longLengthCard::destroyTile(int& x, int& y) {
    //bool isNormal = Interact(x, y);//일반카드 인지 아닌지 확인
    //if (isNormal) {
    //    tileMap[x][y].isActive = false;
    //}
    //srand(time(0)); // 난수 생성을 위한 시드 설정

    //// 선택된 타일

    //for (int i = 0; i < tileMap[y].size(); ++i) {//y에 대해 검사하는 건데 맞는지 모르겠다.
    //    if (i != x) {
    //        // 각 타일에 대한 isNormal 확인
    //        bool isNormal = Interact(i, y);

    //        if (isNormal) {
    //            // 선택된 지점으로부터의 거리 계산
    //            int distance = std::abs(x - i);

    //            // 거리에 따라 파괴 확률 조절
    //            int destructionProbability = 100 - distance * 15;

    //            // 파괴 확률을 [0, 100] 범위 내로 조절
    //            destructionProbability = std::max(0, std::min(100, destructionProbability));


    //            // 난수가 파괴 확률 이내인지 확인하고 파괴 여부 결정
    //            if (rand() % 100 <= destructionProbability) {
    //                tileMap[i][y].isActive = false;
    //            }
    //        }
    //    }
    //}
}
//squareCard::squareCard(CardType type, string name, bool isActive) : Card(type, name, isActive) {
//    type = SQUARE_TYPE;
//    name = "Square";
//    isActive = true;
//}
void squareCard::checkArea() {
    vector<Position>area;
    area.push_back({ -1,-1 });
    area.push_back({ -1,0 });
    area.push_back({ -1,1 });
    area.push_back({ 0,-1 });
    area.push_back({ 0,0 });
    area.push_back({ 0,1 });
    area.push_back({ 1,-1 });
    area.push_back({ 1,0 });
    area.push_back({ 1,1 });
}
void squareCard::destroyTile(int& x, int& y) {
    //bool isNormal = Interact(x, y);//일반카드 인지 아닌지 확인
    //if (isNormal) {
    //    tileMap[x][y].isActive = false;
    //}
    //bool isNormalLeft = Interact(x, y - 1);//왼쪽카드 확인
    //if (isNormalLeft && (rand() % 100<65)) {
    //    tileMap[x][y - 1].isActive = false;
    //}

    //bool isNormalRight = Interact(x, y + 1);//오른쪽 카드 확인
    //if (isNormalRight && (rand() % 100 < 65)) {
    //    tileMap[x][y + 1].isActive = false;
    //}
    //bool isNormalUp = Interact(x - 1, y);//위쪽카드 확인
    //if (isNormalUp && (rand() % 100 < 65)) {
    //    tileMap[x - 1][y].isActive = false;
    //}

    //bool isNormalDown = Interact(x + 1, y);//아래쪽 카드 확인
    //if (isNormalDown && (rand() % 100 < 65)) {
    //    tileMap[x + 1][y].isActive = false;
    //}

    //bool isNormalAboveLeftDiagonal = Interact(x - 1, y - 1);//대각선 카드들 검사
    //if (isNormalAboveLeftDiagonal && (rand() % 100 < 65)) {
    //    tileMap[x - 1][y - 1].isActive = false;
    //}

    //bool isNormalAboveRightDiagonal = Interact(x - 1, y + 1);
    //if (isNormalAboveRightDiagonal && (rand() % 100 < 65)) {
    //    tileMap[x - 1][y + 1].isActive = false;
    //}

    //bool isNormalBelowLeftDiagonal = Interact(x + 1, y - 1);
    //if (isNormalBelowLeftDiagonal && (rand() % 100 < 65)) {
    //    tileMap[x + 1][y - 1].isActive = false;
    //}

    //bool isNormalBelowRightDiagonal = Interact(x + 1, y + 1);
    //if (isNormalBelowRightDiagonal && (rand() % 100 < 65)) {
    //    tileMap[x + 1][y + 1].isActive = false;
    //}
}
//purificationCard::purificationCard(CardType type, string name, bool isActive, bool isClear) : Card(type, name, isActive), isClear(isClear) {
//    type = WIDTH_TYPE;
//    name = "Width";
//    isActive = true;
//    isClear = true;
//}
void purificationCard::checkArea() {
    vector<Position>area;
    area.push_back({ -1,0 });
    area.push_back({ 0,0 });
    area.push_back({ 1,0 });
}
void purificationCard::destroyTile(int& x, int& y) {
    /*tileMap[x][y].isActive = false;
    if (rand() % 100 < 70) {
        tileMap[x][y - 1].isActive = false;
    }
    if (rand() % 100 < 70) {
        tileMap[x][y + 1].isActive = false;
    }*/
}
//crossCard::crossCard(CardType type, string name, bool isActive) : Card(type, name, isActive) {
//    type = CROSS_TYPE;
//    name = "Cross";
//    isActive = true;
//}

void crossCard::checkArea() {
    vector<Position>area;
    area.push_back({ -1,0 });
    area.push_back({ 0,-1 });
    area.push_back({ 0,0 });
    area.push_back({ 0,1 });
    area.push_back({ 1,0 });
}
void crossCard::destroyTile(int& x, int& y) {
    //bool isNormal = Interact(x, y);//일반카드 인지 아닌지 확인
    //if (isNormal) {
    //    tileMap[x][y].isActive = false;
    //}
    //bool isNormalLeft = Interact(x, y - 1);//왼쪽카드 확인
    //if (isNormalLeft) {
    //    tileMap[x][y - 1].isActive = false;
    //}

    //bool isNormalRight = Interact(x, y + 1);//오른쪽 카드 확인
    //if (isNormalRight) {
    //    tileMap[x][y + 1].isActive = false;
    //}
    //bool isNormalUp = Interact(x - 1, y);//위쪽카드 확인
    //if (isNormalUp) {
    //    tileMap[x - 1][y].isActive = false;
    //}

    //bool isNormalDown = Interact(x + 1, y);//아래쪽 카드 확인
    //if (isNormalDown) {
    //    tileMap[x + 1][y].isActive = false;
    //}
}
//purificationCrossCard::purificationCrossCard(CardType type, string name, bool isActive, bool isClear) : purificationCard(type, name, isActive, isClear) {
//    type = PURIFICATION_CROSS_TYPE;
//    name = "Purification_Cross";
//    isActive = true;
//    isClear = true;
//}
void purificationCrossCard::checkArea() {
    vector<Position>area;
    area.push_back({ -1,0 });
    area.push_back({ 0,-1 });
    area.push_back({ 0,0 });
    area.push_back({ 0,1 });
    area.push_back({ 1,0 });
}
void purificationCrossCard::destroyTile(int& x, int& y) {
    /*tileMap[x][y].isActive = false;
    //tileMap[x-1][y].isActive = false;
    tileMap[x+1][y].isActive = false;
    tileMap[x][y-1].isActive = false;
    tileMap[x][y+1].isActive = false;*/
}
//upgradeSquareCard::upgradeSquareCard(CardType type, string name, bool isActive) : Card(type, name, isActive) {
//    type = UPGRADE_SQUARE_TYPE;
//    name = "Upgrade_Square";
//    isActive = true;
//}

void upgradeSquareCard::checkArea() {
    vector<Position>area;
    area.push_back({ -1,-1 });
    area.push_back({ -1,0 });
    area.push_back({ -1,1 });
    area.push_back({ 0,-1 });
    area.push_back({ 0,0 });
    area.push_back({ 0,1 });
    area.push_back({ 1,-1 });
    area.push_back({ 1,0 });
    area.push_back({ 1,1 });
}
void upgradeSquareCard::destroyTile(int& x, int& y) {
    //for (int i =-1; i <2; i++) {//일반타일 형태이면 100%로 파괴
    //    for (int j =-1; j < 2; j++) {
    //        bool isNormal = Interact(x+i, y+j);
    //        if (isNormal) {
    //            tileMap[x+i][y+j].isActive = false;
    //        }
    //    }
    //}
}
//upgradeXCard::upgradeXCard(CardType type, string name, bool isActive) : Card(type, name, isActive) {
//    type = UPGRADE_X_TYPE;
//    name = "Upgrade_X";
//    isActive = true;
//}
void upgradeXCard::checkArea() {
    vector<Position> area;
    area.push_back({ 4, 4 });
    area.push_back({ 3, 3 });
    area.push_back({ 2, 2 });
    area.push_back({ 1, 1 });
    area.push_back({ 0, 0 });
    area.push_back({ -1, -1 });
    area.push_back({ -2, -2 });
    area.push_back({ -3, -3 });
    area.push_back({ -4, -4 });
}
void upgradeXCard::destroyTile(int& x, int& y) {
    //for (int i = - 3; i < 4; i++) {//일반타일 형태이면 100%로 파괴
    //    for (int j = -3; j <4; j++) {
    //        if (i == j) {
    //            bool isNormal = Interact(x + i, y + j);
    //            if (isNormal) {
    //                tileMap[i][j].isActive = false;
    //            }
    //        }
    //    }
    //}
}
//upgradeCrossCard::upgradeCrossCard(CardType type, string name, bool isActive) : Card(type, name, isActive) {
//    type = UPGRADE_CROSS_TYPE;
//    name = "Upgrade_Cross";
//    isActive = true;
//}
void upgradeCrossCard::checkArea() {
    vector<Position>area;
    area.push_back({ 4,0 });
    area.push_back({ 3,0 });
    area.push_back({ 2,0 });
    area.push_back({ 1,0 });
    area.push_back({ 0,0 });
    area.push_back({ -1,0 });
    area.push_back({ -2,0});
    area.push_back({ -3,0 });
    area.push_back({ -4,0 });
    area.push_back({ 0,4 });
    area.push_back({ 0,3 });
    area.push_back({ 0,2 });
    area.push_back({ 0,1 });
    area.push_back({ 0,-1 });
    area.push_back({ 0,-2 });
    area.push_back({ 0,-3 });
    area.push_back({ 0,-4 });
}
void upgradeCrossCard::destroyTile(int& x, int& y) {
    //for (int i = -4; i < 5; i++) {//가로줄 전체 비활성화
    //    bool isNormal = Interact(x + i, y);
    //    if (isNormal) {
    //        tileMap[x + i][y].isActive = false;
    //    }
    //}
    //for (int i = -4; i < 5; i++) {//세로줄 선택 비활성화
    //    if (i != 0) {//겹치는거 제외
    //        bool isNormal = Interact(x, y + i);
    //        if (isNormal) {
    //            tileMap[x + i][y].isActive = false;
    //        }
    //    }
    //}
}
//hellFireCard::hellFireCard(CardType type, string name, bool isActive) : Card(type, name, isActive) {
//    type = HELLFIRE_TYPE;
//    name = "Hell_Fire";
//    isActive = true;
//}
void hellFireCard::checkArea() {
    vector<Position>area;
    area.push_back({ -2,0 });
    area.push_back({ 2,0 });
    area.push_back({ 0,2 });
    area.push_back({ 0,-2});
    area.push_back({ -1,-1 });
    area.push_back({ -1,0 });
    area.push_back({ -1,1 });
    area.push_back({ 0,-1 });
    area.push_back({ 0,0 });
    area.push_back({ 0,1 });
    area.push_back({ 1,-1 });
    area.push_back({ 1,0 });
    area.push_back({ 1,1 });
}
void hellFireCard::destroyTile(int& x, int& y) {
    //for (int i = x - 1; i < x + 2; i++) {//일반타일 형태이면 100%로 파괴
    //    for (int j = y - 1; j < y + 2; j++) {
    //        bool isNormal = Interact(x, y);
    //        if (isNormal) {
    //            tileMap[i][j].isActive = false;
    //        }
    //    }
    //}
    //bool isNormal1, isNormal2, isNormal3, isNormal4;
    //isNormal1 = Interact(x - 2, y);
    //if (isNormal1) {
    //    tileMap[x - 2][y].isActive = false;
    //}
    //isNormal2 = Interact(x + 2, y);
    //if (isNormal2) {
    //    tileMap[x + 2][y].isActive = false;
    //}
    //isNormal3 = Interact(x, y-2);
    //if (isNormal3) {
    //    tileMap[x][y-2].isActive = false;
    //}
    //isNormal4 = Interact(x, y+2);
    //if (isNormal4) {
    //    tileMap[x][y+2].isActive = false;
    //}

}