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

void PrintScreen::PrintTile(short x, short y, string tileStr, unsigned short color)
{
	PrintScreen::PrintString(x + 0, y, "��", color);
	PrintScreen::PrintString(x + 1, y, "��", color);
	PrintScreen::PrintString(x + 2, y, "��", color);
	PrintScreen::PrintString(x + 3, y, "��", color);
	PrintScreen::PrintString(x + 4, y, "��", color);

	PrintScreen::PrintString(x + 0, y + 1, "��", color);
	PrintScreen::PrintString(x + 1, y + 1, tileStr.substr(0, 3), color);
	PrintScreen::PrintString(x + 4, y + 1, "��", color);

	PrintScreen::PrintString(x + 0, y + 2, "��", color);
	PrintScreen::PrintString(x + 1, y + 2, "��", color);
	PrintScreen::PrintString(x + 2, y + 2, "��", color);
	PrintScreen::PrintString(x + 3, y + 2, "��", color);
	PrintScreen::PrintString(x + 4, y + 2, "��", color);
}

