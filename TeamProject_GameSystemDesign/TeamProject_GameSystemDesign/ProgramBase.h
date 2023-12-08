#pragma once
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<Windows.h>
#include<conio.h>
#include <algorithm>
#include <random>
#include <queue>
#include <list>
#pragma warning(disable:4996)

using namespace std;

enum CardType {
    WIDTH_TYPE = 1,                 //(기본)가로 카드
    LENGTH_TYPE = 2,                //(기본)세로 카드
    DOT_TYPE = 3,                   //(기본)점 카드
    X_TYPE = 4,                     //X모양 카드
    LONG_WIDTH_TYPE = 5,            //긴 가로 카드
    LONG_LENGTH_TYPE = 6,           //긴 세로 카드
    SQUARE_TYPE = 7,                // 3*3 네모 카드
    PURIFICATION_TYPE = 8,          //정화 카드
    CROSS_TYPE = 9,                 //(합체) 십자가 카드
    PURIFICATION_CROSS_TYPE = 10,   //(합체) 정화 십자가 카드
    UPGRADE_SQUARE_TYPE = 11,       //(합체) 100% 3*3 네모 카드
    UPGRADE_X_TYPE = 12,            // 7*7 X 모양 카드
    UPGRADE_CROSS_TYPE = 13,        // 15*15 + 모양 카드
    HELLFIRE_TYPE = 14,             // 헬파이어 카드
};

#define INITIAL_PLAYER_DECK_NUMBER 13
#define CARDS_ADDED_PER_STAGE 3
#define MAX_PLAYER_DECK_NUMBER 50

#define PLAYER_STAGE1_TURN 4
#define PLAYER_STAGE2_TURN 7
#define PLAYER_STAGE3_TURN 6
#define PLAYER_STAGE4_TURN 8
#define PLAYER_STAGE5_TURN 7
#define PLAYER_STAGE6_TURN 7
#define PLAYER_STAGE7_TURN 10
#define PLAYER_STAGE8_TURN 8
#define PLAYER_STAGE9_TURN 11