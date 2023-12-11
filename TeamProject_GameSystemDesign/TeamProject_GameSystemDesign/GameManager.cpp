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

void GameManager::ReadFromFile() {

	ifstream fin("map.txt");

	if (!fin) {
		cout << "파일을 열 수 없다";
		return;
	}

	string line;
	vector<string> stageData;

	while (getline(fin, line)) {
		if (line.empty()) {
			// 빈 줄이 나오면 새로운 스테이지 생성
			if (!stageData.empty()) {
				//this->stages.push_back(stageData[0]);
				stageData.clear();
			}
		}
		else {
			stageData.push_back(line);
		}
	}

	fin.close();

}


void GameManager::InputPlayer()
{
	string tileStr;
	int x = 4;
	int y = 4;
	int cardIndex = 0;
	bool keydown_up = false;
	bool keydown_down = false;
	bool keydown_left = false;
	bool keydown_right = false;
	bool keydown_space = false;
	bool keydown_1 = false;
	bool keydown_2 = false;
	bool keydown_r = false;

	while (1)
	{
		if (GetAsyncKeyState(VK_UP) && keydown_up == false)
		{
			keydown_up = true;
			ScreenManager::PrintTile(x * TILE_SIZE_X + TILE_POSITION_X, y * TILE_SIZE_Y + TILE_POSITION_Y, tileStr, COLOR_BLUE);
			if (y - 1 >= 0)
			{
				y--;
			}
			ScreenManager::PrintTile(x * TILE_SIZE_X + TILE_POSITION_X, y * TILE_SIZE_Y + TILE_POSITION_Y, tileStr, COLOR_RED);
		}
		else if (!GetAsyncKeyState(VK_UP))
		{
			keydown_up = false;
		}
		if (GetAsyncKeyState(VK_DOWN) && keydown_down == false)
		{
			keydown_down = true;
			ScreenManager::PrintTile(x * TILE_SIZE_X + TILE_POSITION_X, y * TILE_SIZE_Y + TILE_POSITION_Y, tileStr, COLOR_BLUE);
			if (y + 1 <= 9)
			{
				y++;
			}
			ScreenManager::PrintTile(x * TILE_SIZE_X + TILE_POSITION_X, y * TILE_SIZE_Y + TILE_POSITION_Y, tileStr, COLOR_RED);
		}
		else if (!GetAsyncKeyState(VK_DOWN))
		{
			keydown_down = false;
		}
		if (GetAsyncKeyState(VK_LEFT) && keydown_left == false)
		{
			keydown_left = true;
			ScreenManager::PrintTile(x * TILE_SIZE_X + TILE_POSITION_X, y * TILE_SIZE_Y + TILE_POSITION_Y, tileStr, COLOR_BLUE);
			if (x - 1 >= 0)
			{
				x--;
			}
			ScreenManager::PrintTile(x * TILE_SIZE_X + TILE_POSITION_X, y * TILE_SIZE_Y + TILE_POSITION_Y, tileStr, COLOR_RED);
		}
		else if (!GetAsyncKeyState(VK_LEFT))
		{
			keydown_left = false;
		}
		if (GetAsyncKeyState(VK_RIGHT) && keydown_right == false)
		{
			keydown_right = true;
			ScreenManager::PrintTile(x * TILE_SIZE_X + TILE_POSITION_X, y * TILE_SIZE_Y + TILE_POSITION_Y, tileStr, COLOR_BLUE);
			if (x + 1 <= 9)
			{
				x++;
			}
			ScreenManager::PrintTile(x * TILE_SIZE_X + TILE_POSITION_X, y * TILE_SIZE_Y + TILE_POSITION_Y, tileStr, COLOR_RED);
		}
		else if (!GetAsyncKeyState(VK_RIGHT))
		{
			keydown_right = false;
		}
		if (GetAsyncKeyState(VK_SPACE) && keydown_space == false)
		{
			keydown_space = true;
			if (cardIndex == 1)
			{
				ScreenManager::PrintCard(CARD_HAND1_POSITION_X, CARD_HAND1_POSITION_Y, "HAND1", COLOR_BLUE);
			}
			else if (cardIndex == 2)
			{
				ScreenManager::PrintCard(CARD_HAND2_POSITION_X, CARD_HAND2_POSITION_Y, "HAND2", COLOR_BLUE);
			}
			ScreenManager::PrintTile(x * TILE_SIZE_X + TILE_POSITION_X, y * TILE_SIZE_Y + TILE_POSITION_Y, tileStr, COLOR_BLACK);
		}
		else if (!GetAsyncKeyState(VK_SPACE))
		{
			keydown_space = false;
		}
		if (GetAsyncKeyState(VK_1) && keydown_1 == false)
		{
			keydown_1 = true;
			cardIndex = 1;
			ScreenManager::PrintCard(CARD_HAND1_POSITION_X, CARD_HAND1_POSITION_Y, "HAND1", COLOR_RED);
			ScreenManager::PrintCard(CARD_HAND2_POSITION_X, CARD_HAND2_POSITION_Y, "HAND2", COLOR_GREEN);
		}
		else if (!GetAsyncKeyState(VK_1))
		{
			keydown_1 = false;
		}
		if (GetAsyncKeyState(VK_2) && keydown_2 == false)
		{
			keydown_2 = true;
			cardIndex = 2;
			ScreenManager::PrintCard(CARD_HAND1_POSITION_X, CARD_HAND1_POSITION_Y, "HAND1", COLOR_GREEN);
			ScreenManager::PrintCard(CARD_HAND2_POSITION_X, CARD_HAND2_POSITION_Y, "HAND2", COLOR_RED);
		}
		else if (!GetAsyncKeyState(VK_2))
		{
			keydown_2 = false;
		}
		if (GetAsyncKeyState(VK_R) && keydown_r == false)
		{
			keydown_r = true;
			if (cardIndex == 1)
			{
				ScreenManager::PrintCard(CARD_HAND1_POSITION_X, CARD_HAND1_POSITION_Y, "HAND1", COLOR_YELLOW);
			}
			else if (cardIndex == 2)
			{
				ScreenManager::PrintCard(CARD_HAND2_POSITION_X, CARD_HAND2_POSITION_Y, "HAND2", COLOR_YELLOW);
			}

		}
		else if (!GetAsyncKeyState(VK_R))
		{
			keydown_r = false;
		}
	}
}

void GameManager::UseCard(int x, int y, Card card)
{
	for (int i = 0; i < card.GetArea().size(); i++)
	{
		if (x + card.GetArea()[i].x < 0 || x + card.GetArea()[i].x > 8 || y + card.GetArea()[i].y < 0 || y + card.GetArea()[i].y > 8)
		{
			continue;
		}
	}
}
