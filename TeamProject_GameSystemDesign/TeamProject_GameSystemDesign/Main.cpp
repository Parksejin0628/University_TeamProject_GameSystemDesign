#include"ProgramBase.h"
#include"ScreenManager.h"
#define MAXSIZE 5

int main(void)
{
	string tileStr;
	int redX = 4;
	int redY = 4;
	bool keydown_up = false;
	bool keydown_down = false;
	bool keydown_left = false;
	bool keydown_right = false;

	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			tileStr = "0" + to_string(85);
			if (y == redY && x == redX)
			{
				PrintScreen::PrintTile(5 * x + 40, 3 * y, tileStr, COLOR_RED);
			}
			else
			{
				PrintScreen::PrintTile(5 * x + 40, 3 * y, tileStr, COLOR_BLUE);
			}
			
		}
	}
	while (1)
	{
			if (GetAsyncKeyState(VK_UP) && keydown_up == false)
			{
				keydown_up = true;
				PrintScreen::PrintTile(5 * redX + 40, 3 * redY, tileStr, COLOR_BLUE);
				if (redY - 1 >= 0)
				{
					redY--;
				}
				PrintScreen::PrintTile(5 * redX + 40, 3 * redY, tileStr, COLOR_RED);
			}
			else if (!GetAsyncKeyState(VK_UP))
			{
				keydown_up = false;
			}
			if (GetAsyncKeyState(VK_DOWN) && keydown_down == false)
			{
				keydown_down = true;
				PrintScreen::PrintTile(5 * redX + 40, 3 * redY, tileStr, COLOR_BLUE);
				if (redY + 1 <= 9)
				{
					redY++;
				}
				PrintScreen::PrintTile(5 * redX + 40, 3 * redY, tileStr, COLOR_RED);
			}
			else if (!GetAsyncKeyState(VK_DOWN))
			{
				keydown_down = false;
			}
			if (GetAsyncKeyState(VK_LEFT) && keydown_left == false)
			{
				keydown_left = true;
				PrintScreen::PrintTile(5 * redX + 40, 3 * redY, tileStr, COLOR_BLUE);
				if (redX - 1 >= 0)
				{
					redX--;
				}
				PrintScreen::PrintTile(5 * redX + 40, 3 * redY, tileStr, COLOR_RED);
			}
			else if (!GetAsyncKeyState(VK_LEFT))
			{
				keydown_left = false;
			}
			if (GetAsyncKeyState(VK_RIGHT) && keydown_right == false)
			{
				keydown_right = true;
				PrintScreen::PrintTile(5 * redX + 40, 3 * redY, tileStr, COLOR_BLUE);
				if (redX + 1 <= 9)
				{
					redX++;
				}
				PrintScreen::PrintTile(5 * redX + 40, 3 * redY, tileStr, COLOR_RED);
			}
			else if (!GetAsyncKeyState(VK_RIGHT))
			{
				keydown_right = false;
			}

	}
	


	

	return 0;
}