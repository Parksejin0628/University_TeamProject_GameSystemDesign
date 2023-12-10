#include"GameManager.h"

GameManager::GameManager()
{
	stageIndex = 0;
}

void GameManager::InitGame()
{

}

void GameManager::InitStage(int stageIndex)
{
	
}
/*
void GameManager::InputPlayer()
{
	string tileStr;
	int redX = 4;
	int redY = 4;
	bool keydown_up = false;
	bool keydown_down = false;
	bool keydown_left = false;
	bool keydown_right = false;

	while (1)
	{
		if (GetAsyncKeyState(VK_UP) && keydown_up == false)
		{
			keydown_up = true;
			ScreenManager::PrintTile(5 * redX + 40, 3 * redY, tileStr, COLOR_BLUE);
			if (redY - 1 >= 0)
			{
				redY--;
			}
			ScreenManager::PrintTile(5 * redX + 40, 3 * redY, tileStr, COLOR_RED);
		}
		else if (!GetAsyncKeyState(VK_UP))
		{
			keydown_up = false;
		}
		if (GetAsyncKeyState(VK_DOWN) && keydown_down == false)
		{
			keydown_down = true;
			ScreenManager::PrintTile(5 * redX + 40, 3 * redY, tileStr, COLOR_BLUE);
			if (redY + 1 <= 9)
			{
				redY++;
			}
			ScreenManager::PrintTile(5 * redX + 40, 3 * redY, tileStr, COLOR_RED);
		}
		else if (!GetAsyncKeyState(VK_DOWN))
		{
			keydown_down = false;
		}
		if (GetAsyncKeyState(VK_LEFT) && keydown_left == false)
		{
			keydown_left = true;
			ScreenManager::PrintTile(5 * redX + 40, 3 * redY, tileStr, COLOR_BLUE);
			if (redX - 1 >= 0)
			{
				redX--;
			}
			ScreenManager::PrintTile(5 * redX + 40, 3 * redY, tileStr, COLOR_RED);
		}
		else if (!GetAsyncKeyState(VK_LEFT))
		{
			keydown_left = false;
		}
		if (GetAsyncKeyState(VK_RIGHT) && keydown_right == false)
		{
			keydown_right = true;
			ScreenManager::PrintTile(5 * redX + 40, 3 * redY, tileStr, COLOR_BLUE);
			if (redX + 1 <= 9)
			{
				redX++;
			}
			ScreenManager::PrintTile(5 * redX + 40, 3 * redY, tileStr, COLOR_RED);
		}
		else if (!GetAsyncKeyState(VK_RIGHT))
		{
			keydown_right = false;
		}

}
*/