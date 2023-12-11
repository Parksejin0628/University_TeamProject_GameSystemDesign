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
			ScreenManager::PrintArea(x, y, (cardChoice == 0) ? *cardManager.GetHand().front() : *cardManager.GetHand().back(), COLOR_BLUE, false);
			if (y - 1 >= 0)
			{
				y--;
			}
			ScreenManager::PrintArea(x, y, (cardChoice == 0) ? *cardManager.GetHand().front() : *cardManager.GetHand().back(), COLOR_RED);
		}
			else if (!GetAsyncKeyState(VK_UP))
		{
			keydown_up = false;
		}
		if (GetAsyncKeyState(VK_DOWN) && keydown_down == false)
		{
			keydown_down = true;
			ScreenManager::PrintArea(x, y, (cardChoice == 0) ? *cardManager.GetHand().front() : *cardManager.GetHand().back(), COLOR_BLUE, false);
			if (y + 1 < 9)
			{
				y++;
			}
			ScreenManager::PrintArea(x, y, (cardChoice == 0) ? *cardManager.GetHand().front() : *cardManager.GetHand().back(), COLOR_RED);
		}
		else if (!GetAsyncKeyState(VK_DOWN))
		{
			keydown_down = false;
		}
		if (GetAsyncKeyState(VK_LEFT) && keydown_left == false)
		{
			keydown_left = true;
			ScreenManager::PrintArea(x, y, (cardChoice == 0) ? *cardManager.GetHand().front() : *cardManager.GetHand().back(), COLOR_BLUE, false);
			if (x - 1 >= 0)
			{
				x--;
			}
			ScreenManager::PrintArea(x, y, (cardChoice == 0) ? *cardManager.GetHand().front() : *cardManager.GetHand().back(), COLOR_RED);
		}
		else if (!GetAsyncKeyState(VK_LEFT))
		{
			keydown_left = false;
		}
		if (GetAsyncKeyState(VK_RIGHT) && keydown_right == false)
		{
			keydown_right = true;
			ScreenManager::PrintArea(x, y, (cardChoice == 0) ? *cardManager.GetHand().front() : *cardManager.GetHand().back(), COLOR_BLUE, false);
			if (x + 1 < 9)
			{
				x++;
			}
			ScreenManager::PrintArea(x, y, (cardChoice == 0) ? *cardManager.GetHand().front() : *cardManager.GetHand().back(), COLOR_RED);
		}
		else if (!GetAsyncKeyState(VK_RIGHT))
		{
			keydown_right = false;
		}
		if (GetAsyncKeyState(VK_SPACE) && keydown_space == false)
		{
			keydown_space = true;
			if (cardChoice == 0)
			{
				ScreenManager::PrintCard(CARD_HAND1_POSITION_X, CARD_HAND1_POSITION_Y, *cardManager.GetHand().front(), COLOR_BLUE);
			}
			else if (cardChoice == 1)
			{
				ScreenManager::PrintCard(CARD_HAND2_POSITION_X, CARD_HAND2_POSITION_Y, *cardManager.GetHand().back(), COLOR_BLUE);
			}
			ScreenManager::PrintTile(x, y, tileStr, COLOR_BLACK);
		}
		else if (!GetAsyncKeyState(VK_SPACE))
		{
			keydown_space = false;
		}
		if (GetAsyncKeyState(VK_1) && keydown_1 == false)
		{
			keydown_1 = true;
			ScreenManager::PrintArea(x, y, (cardChoice == 0) ? *cardManager.GetHand().front() : *cardManager.GetHand().back(), COLOR_BLUE, false);
			cardChoice = 0;
			ScreenManager::PrintArea(x, y, (cardChoice == 0) ? *cardManager.GetHand().front() : *cardManager.GetHand().back(), COLOR_RED);
			ScreenManager::PrintCard(CARD_HAND1_POSITION_X, CARD_HAND1_POSITION_Y, *cardManager.GetHand().front(), COLOR_RED);
			ScreenManager::PrintCard(CARD_HAND2_POSITION_X, CARD_HAND2_POSITION_Y, *cardManager.GetHand().back(), COLOR_GREEN);
		}
		else if (!GetAsyncKeyState(VK_1))
		{
			keydown_1 = false;
		}
		if (GetAsyncKeyState(VK_2) && keydown_2 == false)
		{
			keydown_2 = true;
			ScreenManager::PrintArea(x, y, (cardChoice == 0) ? *cardManager.GetHand().front() : *cardManager.GetHand().back(), COLOR_BLUE, false);
			cardChoice = 1;
			ScreenManager::PrintArea(x, y, (cardChoice == 0) ? *cardManager.GetHand().front() : *cardManager.GetHand().back(), COLOR_RED);
			ScreenManager::PrintCard(CARD_HAND1_POSITION_X, CARD_HAND1_POSITION_Y, *cardManager.GetHand().front(), COLOR_GREEN);
			ScreenManager::PrintCard(CARD_HAND2_POSITION_X, CARD_HAND2_POSITION_Y, *cardManager.GetHand().back(), COLOR_RED);
		}
		else if (!GetAsyncKeyState(VK_2))
		{
			keydown_2 = false;
		}
		if (GetAsyncKeyState(VK_R) && keydown_r == false)
		{
			keydown_r = true;
			if (cardChoice == 0)
			{
				ScreenManager::PrintCard(CARD_HAND1_POSITION_X, CARD_HAND1_POSITION_Y, *cardManager.GetHand().front(), COLOR_YELLOW);
			}
			else if (cardChoice == 1)
			{
				ScreenManager::PrintCard(CARD_HAND2_POSITION_X, CARD_HAND2_POSITION_Y, *cardManager.GetHand().back(), COLOR_YELLOW);
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

CardManager& GameManager::GetCardManager()
{
	return cardManager;
}
TileManager& GameManager::GetTIleManager()
{
	return tileManager;
}
