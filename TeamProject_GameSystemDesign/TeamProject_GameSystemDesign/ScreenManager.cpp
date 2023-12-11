#pragma once
#include"ScreenManager.h"

void ScreenManager::SetColor(unsigned short color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

	return;
}

void ScreenManager::Goto_xy(short x, short y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	Position pos = { x, y };
	SetConsoleCursorPosition(handle, pos);
}

void ScreenManager::PrintString(short x, short y, string printStr, unsigned short color)
{
	SetColor(color);
	Goto_xy(x, y);
	cout << printStr;
	SetColor(COLOR_WHITE);
}

void ScreenManager::PrintTile(short x, short y, string tileStr, unsigned short color)
{
	PrintString(x + 0, y, "忙", color);
	PrintString(x + 1, y, "式", color);
	PrintString(x + 2, y, "式", color);
	PrintString(x + 3, y, "式", color);
	PrintString(x + 4, y, "忖", color);

	PrintString(x + 0, y + 1, "弛", color);
	PrintString(x + 1, y + 1, tileStr.substr(0, 3), color);
	PrintString(x + 4, y + 1, "弛", color);

	PrintString(x + 0, y + 2, "戌", color);
	PrintString(x + 1, y + 2, "式", color);
	PrintString(x + 2, y + 2, "式", color);
	PrintString(x + 3, y + 2, "式", color);
	PrintString(x + 4, y + 2, "戎", color);
}

void ScreenManager::PrintCard(short x, short y, string cardName, unsigned short color)
{
	for (int ySize = 0; ySize < CARD_SIZE_Y; ySize++)
	{
		for (int xSize = 0; xSize < CARD_SIZE_X; xSize++)
		{
			if (xSize == 0)
			{
				if (ySize == 0)
				{
					PrintString(x + xSize, y + ySize, "忙", color);
				}
				else if (ySize == CARD_SIZE_Y - 1)
				{
					PrintString(x + xSize, y + ySize, "戌", color);
				}
				else
				{
					PrintString(x + xSize, y + ySize, "弛", color);
				}
			}
			else if (xSize == CARD_SIZE_X - 1)
			{
				if (ySize == 0)
				{
					PrintString(x + xSize, y + ySize, "忖", color);
				}
				else if (ySize == CARD_SIZE_Y - 1)
				{
					PrintString(x + xSize, y + ySize, "戎", color);
				}
				else
				{
					PrintString(x + xSize, y + ySize, "弛", color);
				}
			}
			else if (ySize == 0 || ySize == CARD_SIZE_Y - 1)
			{
				PrintString(x + xSize, y + ySize, "式", color);
			}
		}
	}


	
	PrintString(x + CARD_SIZE_X, y + CARD_SIZE_Y, "", color);
}

void ScreenManager::PrintStage(int stageIndex, unsigned short color)
{
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			PrintTile(x * TILE_SIZE_X + TILE_POSITION_X, y * TILE_SIZE_Y + TILE_POSITION_Y, "", color);
		}
	}
}

void ScreenManager::PrintInGame(int stageIndex, GameManager& gm)
{
	PrintStage(stageIndex, COLOR_BLUE);
	PrintCard(CARD_HAND1_POSITION_X, CARD_HAND1_POSITION_Y, "HAND1", COLOR_GREEN);
	PrintCard(CARD_HAND2_POSITION_X, CARD_HAND2_POSITION_Y, "HAND2", COLOR_GREEN);
	PrintCard(CARD_WAIT1_POSITION_X, CARD_WAIT1_POSITION_Y, "WAIT1", COLOR_GREEN);
	PrintCard(CARD_WAIT2_POSITION_X, CARD_WAIT2_POSITION_Y, "WAIT2", COLOR_GREEN);
	PrintCard(CARD_TOMB_POSITION_X, CARD_TOMB_POSITION_Y, "TOMB", COLOR_GREEN);
	PrintCard(CARD_DECK_POSITION_X, CARD_DECK_POSITION_Y, "DECK", COLOR_GREEN);
	PrintString(TEXT_HAND_POSITION_X, TEXT_HAND_POSITION_Y, "HAND", COLOR_YELLOW);
	PrintString(TEXT_NEXT_POSITION_X, TEXT_NEXT_POSITION_Y, "NEXT", COLOR_YELLOW);
	PrintString(TEXT_REMOVE_POSITION_X, TEXT_REMOVE_POSITION_Y, "REMOVE : ", COLOR_YELLOW);
	PrintString(TEXT_1_POSITION_X, TEXT_1_POSITION_Y, "1", COLOR_YELLOW);
	PrintString(TEXT_2_POSITION_X, TEXT_2_POSITION_Y, "2", COLOR_YELLOW);
	PrintString(TEXT_TOMB_POSITION_X, TEXT_TOMB_POSITION_Y, "TOMB", COLOR_YELLOW);
	PrintString(TEXT_DECK_POSITION_X, TEXT_DECK_POSITION_Y, "DECK", COLOR_YELLOW);
	PrintString(1, 27, " ");

}

