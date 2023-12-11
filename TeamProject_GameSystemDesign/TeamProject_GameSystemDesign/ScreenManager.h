#pragma once
#include"ProgramBase.h"
#include"GameManager.h"

#define TILE_SIZE_X 5		//Ÿ�� �ϳ��� X ������
#define TILE_SIZE_Y 3		//Ÿ�� �ϳ��� Y ������
#define TILE_POSITION_X 0 //Ÿ�� ��ü�� x��ǥ
#define TILE_POSITION_Y 0  //Ÿ�� ��ü�� y��ǥ
#define CARD_SIZE_X 11
#define CARD_SIZE_Y 11
#define CARD_HAND1_POSITION_X 50
#define CARD_HAND1_POSITION_Y 0
#define CARD_HAND2_POSITION_X 50
#define CARD_HAND2_POSITION_Y 15
#define CARD_WAIT1_POSITION_X 65
#define CARD_WAIT1_POSITION_Y 7
#define CARD_WAIT2_POSITION_X 80
#define CARD_WAIT2_POSITION_Y 7
#define CARD_TOMB_POSITION_X 95
#define CARD_TOMB_POSITION_Y 0
#define CARD_DECK_POSITION_X 95
#define CARD_DECK_POSITION_Y 15
#define TEXT_REMOVE_POSITION_X 70
#define TEXT_REMOVE_POSITION_Y 0
#define TEXT_HAND_POSITION_X 54
#define TEXT_HAND_POSITION_Y 12
#define TEXT_NEXT_POSITION_X 76
#define TEXT_NEXT_POSITION_Y 5
#define TEXT_1_POSITION_X 55
#define TEXT_1_POSITION_Y 11
#define TEXT_2_POSITION_X 55
#define TEXT_2_POSITION_Y 14
#define TEXT_TOMB_POSITION_X 98
#define TEXT_TOMB_POSITION_Y 11
#define TEXT_DECK_POSITION_X 98
#define TEXT_DECK_POSITION_Y 14

enum Color
{
	COLOR_BLACK = 0, COLOR_BLUE, COLOR_GREEN, COLOR_BLUEGREEN, COLOR_RED, COLOR_PURPLE, COLOR_YELLOW, COLOR_WHITE,
	COLOR_GRAY, COLOR_LIGHTBLUE, COLOR_LIGHTGREEN, COLOR_LIGHTBLUEGREEN, COLOR_LIGHTRED, COLOR_LIGHTPURPLE, COLOR_LIGHTYELLOW, COLOR_LIGHTWHITE
};
//COORD�� window.h ������Ͽ��� x, y��ǥ�� ����ִ� ����ü
//������� : short X / short Y
typedef COORD Position;

class GameManager;

class ScreenManager
{
private:

public:
	static void SetColor(unsigned short color = COLOR_WHITE);	//����� ���� ��ȭ��Ű�� �Լ�
	static void Goto_xy(short x, short y);						//��� ���� �κ��� x, y�κ����� �ű�, ��������� (0, 0)�̴�. ����� �����ϸ� ���ϴ�.
	static void PrintString(short x, short y, string printStr, unsigned short color = COLOR_WHITE);	//�ܼ��� x, y��ǥ�� color ������ printStr�� ���
	static void PrintTile(short x, short y, string tileStr = "   ", unsigned short color = COLOR_WHITE); //�ܼ� x, y��ǥ�� color ���� Ÿ�� ���, Ÿ�� �ȿ� tileStr ���
	static void PrintCard(short x, short y, string cardName = "cardName", unsigned short color = COLOR_WHITE);
	static void PrintStage(int stageIndex, unsigned short color = COLOR_WHITE);
	static void PrintInGame(int stageIndex, GameManager& gm);
};
