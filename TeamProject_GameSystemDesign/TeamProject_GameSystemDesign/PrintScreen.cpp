#pragma once
#include"PrintScreen.h"

void PrintScreen::setColor(unsigned short color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

	return;
}

void PrintScreen::goto_xy(short x, short y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	Position pos = { x, y };
	SetConsoleCursorPosition(handle, pos);
}

void PrintScreen::goto_xy(Position pos)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, pos);
}

void PrintScreen::printScreen(short x, short y, string printStr, unsigned short color)
{
	setColor(color);
	goto_xy(x, y);
	cout << printStr;
	setColor(COLOR_WHITE);
}

