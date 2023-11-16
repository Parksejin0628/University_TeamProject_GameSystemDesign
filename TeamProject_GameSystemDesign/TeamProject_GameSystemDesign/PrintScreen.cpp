#pragma once
#include"PrintScreen.h"

void PrintScreen::SetColor(unsigned short color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

	return;
}

void PrintScreen::Goto_xy(short x, short y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	Position pos = { x, y };
	SetConsoleCursorPosition(handle, pos);
}

void PrintScreen::PrintString(short x, short y, string printStr, unsigned short color)
{
	SetColor(color);
	Goto_xy(x, y);
	cout << printStr;
	SetColor(COLOR_WHITE);
}

