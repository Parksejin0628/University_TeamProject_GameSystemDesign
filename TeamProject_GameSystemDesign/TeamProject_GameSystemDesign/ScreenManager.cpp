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
	PrintString(x + 0, y, "┌", color);
	PrintString(x + 1, y, "─", color);
	PrintString(x + 2, y, "─", color);
	PrintString(x + 3, y, "─", color);
	PrintString(x + 4, y, "┐", color);

	PrintString(x + 0, y + 1, "│", color);
	PrintString(x + 1, y + 1, tileStr.substr(0, 3), color);
	PrintString(x + 4, y + 1, "│", color);

	PrintString(x + 0, y + 2, "└", color);
	PrintString(x + 1, y + 2, "─", color);
	PrintString(x + 2, y + 2, "─", color);
	PrintString(x + 3, y + 2, "─", color);
	PrintString(x + 4, y + 2, "┘", color);
}

void ScreenManager::PrintCard(short x, short y, Card card, unsigned short color)
{
	for (int ySize = 0; ySize < CARD_SIZE_Y; ySize++)
	{
		for (int xSize = 0; xSize < CARD_SIZE_X; xSize++)
		{
			if (xSize == 0)
			{
				if (ySize == 0)
				{
					PrintString(x + xSize, y + ySize, "┌", color);
				}
				else if (ySize == CARD_SIZE_Y - 1)
				{
					PrintString(x + xSize, y + ySize, "└", color);
				}
				else
				{
					PrintString(x + xSize, y + ySize, "│", color);
				}
			}
			else if (xSize == CARD_SIZE_X - 1)
			{
				if (ySize == 0)
				{
					PrintString(x + xSize, y + ySize, "┐", color);
				}
				else if (ySize == CARD_SIZE_Y - 1)
				{
					PrintString(x + xSize, y + ySize, "┘", color);
				}
				else
				{
					PrintString(x + xSize, y + ySize, "│", color);
				}
			}
			else if (ySize == 0 || ySize == CARD_SIZE_Y - 1)
			{
				PrintString(x + xSize, y + ySize, "─", color);
			}
		}
	}
	for (int j = 1; j < CARD_SIZE_Y - 1; j++)
	{
		for (int i = 1; i < CARD_SIZE_X - 1; i++)
		{
			PrintString(x + i, y + j, " ");
		}
	}
	for (int i = 0; i < card.GetArea().size(); i++)
	{
		if (card.GetArea()[i].x > 4 || card.GetArea()[i].x < -4 || card.GetArea()[i].y > 4 || card.GetArea()[i].y < -4)
		{
			continue;
		}
		PrintString(x + CARD_SIZE_X/2 + card.GetArea()[i].x, y + CARD_SIZE_Y / 2 + card.GetArea()[i].y, "■", color);
	}



	PrintString(x + CARD_SIZE_X, y + CARD_SIZE_Y, "", color);
}

void ScreenManager::PrintStage(TileManager& tileManager, unsigned short color)
{
	static Tile previousTile[9][9];
	static bool init = false;
	if (!init)
	{
		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 9; x++)
			{
				PrintTile(x * TILE_SIZE_X + TILE_POSITION_X, y * TILE_SIZE_Y + TILE_POSITION_Y, "   ", COLOR_GRAY);
			}
		}
		init = true;
	}
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			if (previousTile[y][x].GetType() != tileManager.tile[y][x].GetType())
			{
				if (tileManager.tile[y][x].GetType() == VOID_TILE)
				{
					PrintTile(x * TILE_SIZE_X + TILE_POSITION_X, y * TILE_SIZE_Y + TILE_POSITION_Y, "   ", COLOR_GRAY);
				}
				else if (tileManager.tile[y][x].GetType() == SPECIAL_TILE)
				{
					PrintTile(x * TILE_SIZE_X + TILE_POSITION_X, y * TILE_SIZE_Y + TILE_POSITION_Y, "", COLOR_PURPLE);
				}
				else
				{
					PrintTile(x * TILE_SIZE_X + TILE_POSITION_X, y * TILE_SIZE_Y + TILE_POSITION_Y, "", color);
				}
				previousTile[y][x].Create(tileManager.tile[y][x].GetType());
			}
			
		}
	}
}

void ScreenManager::PrintInGame(GameManager& gm)
{
	PrintStage(gm.GetTIleManager());
	PrintCard(CARD_HAND1_POSITION_X, CARD_HAND1_POSITION_Y, *gm.GetCardManager().GetHand().front() , COLOR_GREEN);
	PrintCard(CARD_HAND2_POSITION_X, CARD_HAND2_POSITION_Y, *gm.GetCardManager().GetHand().back(), COLOR_GREEN);
	PrintCard(CARD_WAIT1_POSITION_X, CARD_WAIT1_POSITION_Y, *gm.GetCardManager().GetReady().front(), COLOR_GREEN);
	PrintCard(CARD_WAIT2_POSITION_X, CARD_WAIT2_POSITION_Y, *gm.GetCardManager().GetReady().front(), COLOR_GREEN);
	PrintCard(CARD_TOMB_POSITION_X, CARD_TOMB_POSITION_Y, Card(), COLOR_GREEN);
	PrintCard(CARD_DECK_POSITION_X, CARD_DECK_POSITION_Y, Card(), COLOR_GREEN);
	PrintString(TEXT_HAND_POSITION_X, TEXT_HAND_POSITION_Y, "HAND", COLOR_YELLOW);
	PrintString(TEXT_NEXT_POSITION_X, TEXT_NEXT_POSITION_Y, "NEXT", COLOR_YELLOW);
	PrintString(TEXT_REMOVE_POSITION_X, TEXT_REMOVE_POSITION_Y, "TURN : " + to_string(gm.GetNowTurn()) + " / " + to_string(gm.GetMaxTurn()), COLOR_YELLOW);
	PrintString(TEXT_1_POSITION_X, TEXT_1_POSITION_Y, "1", COLOR_YELLOW);
	PrintString(TEXT_2_POSITION_X, TEXT_2_POSITION_Y, "2", COLOR_YELLOW);
	PrintString(TEXT_TOMB_POSITION_X, TEXT_TOMB_POSITION_Y, "TOMB", COLOR_YELLOW);
	PrintString(TEXT_DECK_POSITION_X, TEXT_DECK_POSITION_Y, "DECK", COLOR_YELLOW);
	PrintString(1, 27, " ");

}

void ScreenManager::PrintArea(short x, short y, Card card, GameManager& gm, unsigned short color, bool printProbability)
{
	
	for (int i = 0; i < card.GetArea().size(); i++)
	{
		if ( x + card.GetArea()[i].x > 8 || x + card.GetArea()[i].x < 0 || y + card.GetArea()[i].y > 8 || y + card.GetArea()[i].y < 0)
		{
			continue;
		}
		
		if (gm.GetTIleManager().tile[y + card.GetArea()[i].y][x + card.GetArea()[i].x].GetType() == VOID_TILE)

			continue;		{
		}
		PrintTile((x + card.GetArea()[i].x) * TILE_SIZE_X + TILE_POSITION_X, (y + card.GetArea()[i].y)*TILE_SIZE_Y + TILE_POSITION_Y, printProbability ? to_string(card.GetArea()[i].probability) : "   ", color);
	}
	
}


