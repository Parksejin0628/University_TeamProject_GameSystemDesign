#include "card.h"
#include <cstdlib>

Card::Card(CardType type) {
    
}

vector<Area>& Card::GetArea()
{
    return area;
}

bool Card::CreateMergedCard(Card& other, Card& result) {
    if ((type == WIDTH_TYPE && other.type == LENGTH_TYPE) || (type == LENGTH_TYPE && other.type == WIDTH_TYPE)) {
        result = CrossCard();
        return true;
    }
    else if ((type == PURIFICATION_TYPE && other.type == PURIFICATION_TYPE)) {
        return purificationCard(PURIFICATION_CROSS_TYPE, "Purification Cross", true,true);
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
}

WidthCard::WidthCard() : Card(WIDTH_TYPE)
{
    area.push_back({ 0,0, 100});
    area.push_back({ 1,0 , 50});
    area.push_back({ -1,0 , 50});
}


WidthCard::WidthCard() : Card(WIDTH_TYPE)
{
    area.push_back({ 0,0, 100 });
    area.push_back({ 1,0 , 50 });
    area.push_back({ -1,0 , 50 });
}

LengthCard::LengthCard() : Card(LENGTH_TYPE)
{
    area.push_back({ 0,0, 100 });
    area.push_back({ 1,0 , 50 });
    area.push_back({ -1,0 , 50 });
}

DotCard::DotCard() : Card(DOT_TYPE)
{
    area.push_back({ 0,0, 100 });
    area.push_back({ 1,0 , 50 });
    area.push_back({ -1,0 , 50 });
}

XCard::XCard() : Card(X_TYPE)
{
    area.push_back({ 0,0, 100 });
    area.push_back({ 1,0 , 50 });
    area.push_back({ -1,0 , 50 });
}

LongWidthCard::LongWidthCard() : Card(LONG_WIDTH_TYPE)
{
    area.push_back({ 0,0, 100 });
    area.push_back({ 1,0 , 50 });
    area.push_back({ -1,0 , 50 });
}

LongLengthCard::LongLengthCard() : Card(LONG_WIDTH_TYPE)
{
    area.push_back({ 0,0, 100 });
    area.push_back({ 1,0 , 50 });
    area.push_back({ -1,0 , 50 });
}

SquareCard::SquareCard() : Card(SQUARE_TYPE)
{
    area.push_back({ 0,0, 100 });
    area.push_back({ 1,0 , 50 });
    area.push_back({ -1,0 , 50 });
}

PurificationCard::PurificationCard() : Card(PURIFICATION_TYPE)
{
    area.push_back({ 0,0, 100 });
    area.push_back({ 1,0 , 50 });
    area.push_back({ -1,0 , 50 });
}

CrossCard::CrossCard() : Card(CROSS_TYPE)
{
    area.push_back({ 0,0, 100 });
    area.push_back({ 1,0 , 50 });
    area.push_back({ -1,0 , 50 });
}

PurificationCrossCard::PurificationCrossCard() : Card(PURIFICATION_CROSS_TYPE)
{
    area.push_back({ 0,0, 100 });
    area.push_back({ 1,0 , 50 });
    area.push_back({ -1,0 , 50 });
}
UpgradeSquareCard::UpgradeSquareCard() : Card(UPGRADE_SQUARE_TYPE)
{
    area.push_back({ 0,0, 100 });
    area.push_back({ 1,0 , 50 });
    area.push_back({ -1,0 , 50 });
}
UpgradeXCard::UpgradeXCard() : Card(UPGRADE_X_TYPE)
{
    area.push_back({ 0,0, 100 });
    area.push_back({ 1,0 , 50 });
    area.push_back({ -1,0 , 50 });
}
UpgradeCrossCard::UpgradeCrossCard() : Card(UPGRADE_CROSS_TYPE)
{
    area.push_back({ 0,0, 100 });
    area.push_back({ 1,0 , 50 });
    area.push_back({ -1,0 , 50 });
}
HellFireCard::HellFireCard() : Card(HELLFIRE_TYPE)
{
    area.push_back({ 0,0, 100 });
    area.push_back({ 1,0 , 50 });
    area.push_back({ -1,0 , 50 });
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
void dotCard::destroyTile(int& x, int& y) {
    //bool isNormal = Interact(x, y);//일반카드 인지 아닌지 확인
    //if (isNormal) {
    //    tileMap[x][y].isActive = false;
    //}
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

void purificationCard::destroyTile(int& x, int& y) {
    /*tileMap[x][y].isActive = false;
    if (rand() % 100 < 70) {
        tileMap[x][y - 1].isActive = false;
    }
    if (rand() % 100 < 70) {
        tileMap[x][y + 1].isActive = false;
    }*/
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

void purificationCrossCard::destroyTile(int& x, int& y) {
    /*tileMap[x][y].isActive = false;
    tileMap[x-1][y].isActive = false;
    tileMap[x+1][y].isActive = false;
    tileMap[x][y-1].isActive = false;
    tileMap[x][y+1].isActive = false;*/
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