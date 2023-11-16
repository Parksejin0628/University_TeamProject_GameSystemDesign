#pragma once
#include"ProgramBase.h"

#define TILESIZE_X 5
#define TILESIZE_Y 3

enum Color
{
	COLOR_BLACK = 0, COLOR_BLUE, COLOR_GREEN, COLOR_BLUEGREEN, COLOR_RED, COLOR_PURPLE, COLOR_YELLOW, COLOR_WHITE,
	COLOR_GRAY, COLOR_LIGHTBLUE, COLOR_LIGHTGREEN, COLOR_LIGHTBLUEGREEN, COLOR_LIGHTRED, COLOR_LIGHTPURPLE, COLOR_LIGHTYELLOW, COLOR_LIGHTWHITE
};
//COORD�� window.h ������Ͽ��� x, y��ǥ�� ����ִ� ����ü
//������� : short X / short Y
typedef COORD Position;

class PrintScreen
{
private:

public:
	static void SetColor(unsigned short color = COLOR_WHITE);	//����� ���� ��ȭ��Ű�� �Լ�
	static void Goto_xy(short x, short y);						//��� ���� �κ��� x, y�κ����� �ű�, ��������� (0, 0)�̴�. ����� �����ϸ� ���ϴ�.
	static void PrintString(short x, short y, string printStr, unsigned short color = COLOR_WHITE);	//�ܼ��� x, y��ǥ�� color ������ printStr�� ���
	static void PrintTile(short x, short y, string tileStr = "   ", unsigned short color = COLOR_WHITE); //�ܼ� x, y��ǥ�� color ���� Ÿ�� ���, Ÿ�� �ȿ� tileStr ���
};
