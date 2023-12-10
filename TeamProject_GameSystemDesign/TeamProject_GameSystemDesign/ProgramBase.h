#pragma once
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<Windows.h>
#include<conio.h>
#include <fstream>
#include <algorithm>
#include <random>
#include <queue>
#include <list>
#pragma warning(disable:4996)

using namespace std;

enum CardType {
    WIDTH_TYPE = 1,                 //(�⺻)���� ī��
    LENGTH_TYPE = 2,                //(�⺻)���� ī��
    DOT_TYPE = 3,                   //(�⺻)�� ī��
    X_TYPE = 4,                     //X��� ī��
    LONG_WIDTH_TYPE = 5,            //�� ���� ī��
    LONG_LENGTH_TYPE = 6,           //�� ���� ī��
    SQUARE_TYPE = 7,                // 3*3 �׸� ī��
    PURIFICATION_TYPE = 8,          //��ȭ ī��
    CROSS_TYPE = 9,                 //(��ü) ���ڰ� ī��
    PURIFICATION_CROSS_TYPE = 10,   //(��ü) ��ȭ ���ڰ� ī��
    UPGRADE_SQUARE_TYPE = 11,       //(��ü) 100% 3*3 �׸� ī��
    UPGRADE_X_TYPE = 12,            // 7*7 X ��� ī��
    UPGRADE_CROSS_TYPE = 13,        // 15*15 + ��� ī��
    HELLFIRE_TYPE = 14,             // �����̾� ī��
};

enum TileType
{
    VOID_TILE = 0,
    NORMAL_TILE = 1,
    SPECIAL_TILE = 9,
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

#define ROW 9
#define COL 9