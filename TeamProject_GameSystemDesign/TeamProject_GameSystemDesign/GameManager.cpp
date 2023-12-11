#include"GameManager.h"

GameManager::GameManager() : tileManager(), cardManager(), stageIndex(1)
{
	InitStage(1);
}

void GameManager::InitGame()
{

}

void GameManager::InitStage(int stageIndex)
{
	tileManager.InitTile(stageIndex);
	nowTurn = 1;
	cardChoice = 1;
	switch (stageIndex)
	{
	case 1:
		maxTurn = PLAYER_STAGE1_TURN;
		break;
	case 2:
		maxTurn = PLAYER_STAGE2_TURN;
		break;
	case 3:
		maxTurn = PLAYER_STAGE3_TURN;
		break;
	case 4:
		maxTurn = PLAYER_STAGE4_TURN;
		break;
	case 5:
		maxTurn = PLAYER_STAGE5_TURN;
		break;
	case 6:
		maxTurn = PLAYER_STAGE6_TURN;
		break;
	case 7:
		maxTurn = PLAYER_STAGE7_TURN;
		break;
	case 8:
		maxTurn = PLAYER_STAGE8_TURN;
		break;
	case 9:
		maxTurn = PLAYER_STAGE9_TURN;
		break;
	}
}

void GameManager::ReadFromFile() {

	ifstream fin("map.txt");

	if (!fin) {
		cout << "������ �� �� ����";
		return;
	}

	string line;
	vector<string> stageData;

	while (getline(fin, line)) {
		if (line.empty()) {
			// �� ���� ������ ���ο� �������� ����
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
	static int x = 4;
	static int y = 4;
	static bool keydown_up = false;
	static bool keydown_down = false;
	static bool keydown_left = false;
	static bool keydown_right = false;
	static bool keydown_space = false;
	static bool keydown_1 = false;
	static bool keydown_2 = false;
	static bool keydown_r = false;

	while (1)
	{
		if (GetAsyncKeyState(VK_UP) && keydown_up == false)
		{
			keydown_up = true;
			if (tileManager.tile[y][x].GetType() == VOID_TILE)
			{
				ScreenManager::PrintTile(x * TILE_SIZE_X + TILE_POSITION_X, y * TILE_SIZE_Y + TILE_POSITION_Y, "   ", COLOR_GRAY);
			}
			ScreenManager::PrintArea(x, y, (cardChoice == 0) ? *cardManager.GetHand().front() : *cardManager.GetHand().back(), *this, COLOR_WHITE, false);
			if (y - 1 >= 0)
			{
				y--;
			}
			ScreenManager::PrintArea(x, y, (cardChoice == 0) ? *cardManager.GetHand().front() : *cardManager.GetHand().back(), *this, COLOR_RED);
			if (tileManager.tile[y][x].GetType() == VOID_TILE)
			{
				ScreenManager::PrintTile(x * TILE_SIZE_X + TILE_POSITION_X, y * TILE_SIZE_Y + TILE_POSITION_Y, "   ", COLOR_RED);
			}
		}
		else if (!GetAsyncKeyState(VK_UP))
		{
			keydown_up = false;
		}
		if (GetAsyncKeyState(VK_DOWN) && keydown_down == false)
		{
			if (tileManager.tile[y][x].GetType() == VOID_TILE)
			{
				ScreenManager::PrintTile(x * TILE_SIZE_X + TILE_POSITION_X, y * TILE_SIZE_Y + TILE_POSITION_Y, "   ", COLOR_GRAY);
			}
			keydown_down = true;
			ScreenManager::PrintArea(x, y, (cardChoice == 0) ? *cardManager.GetHand().front() : *cardManager.GetHand().back(), *this, COLOR_WHITE, false);
			if (y + 1 < 9)
			{
				y++;
			}
			ScreenManager::PrintArea(x, y, (cardChoice == 0) ? *cardManager.GetHand().front() : *cardManager.GetHand().back(), *this, COLOR_RED);
			if (tileManager.tile[y][x].GetType() == VOID_TILE)
			{
				ScreenManager::PrintTile(x * TILE_SIZE_X + TILE_POSITION_X, y * TILE_SIZE_Y + TILE_POSITION_Y, "   ", COLOR_RED);
			}
		}
		else if (!GetAsyncKeyState(VK_DOWN))
		{
			keydown_down = false;
		}
		if (GetAsyncKeyState(VK_LEFT) && keydown_left == false)
		{
			if (tileManager.tile[y][x].GetType() == VOID_TILE)
			{
				ScreenManager::PrintTile(x * TILE_SIZE_X + TILE_POSITION_X, y * TILE_SIZE_Y + TILE_POSITION_Y, "   ", COLOR_GRAY);
			}
			keydown_left = true;
			ScreenManager::PrintArea(x, y, (cardChoice == 0) ? *cardManager.GetHand().front() : *cardManager.GetHand().back(), *this, COLOR_WHITE, false);
			if (x - 1 >= 0)
			{
				x--;
			}
			ScreenManager::PrintArea(x, y, (cardChoice == 0) ? *cardManager.GetHand().front() : *cardManager.GetHand().back(), *this, COLOR_RED);
			if (tileManager.tile[y][x].GetType() == VOID_TILE)
			{
				ScreenManager::PrintTile(x * TILE_SIZE_X + TILE_POSITION_X, y * TILE_SIZE_Y + TILE_POSITION_Y, "   ", COLOR_RED);
			}
		}
		else if (!GetAsyncKeyState(VK_LEFT))
		{
			keydown_left = false;
		}
		if (GetAsyncKeyState(VK_RIGHT) && keydown_right == false)
		{
			if (tileManager.tile[y][x].GetType() == VOID_TILE)
			{
				ScreenManager::PrintTile(x * TILE_SIZE_X + TILE_POSITION_X, y * TILE_SIZE_Y + TILE_POSITION_Y, "   ", COLOR_GRAY);
			}
			keydown_right = true;
			ScreenManager::PrintArea(x, y, (cardChoice == 0) ? *cardManager.GetHand().front() : *cardManager.GetHand().back(), *this, COLOR_WHITE, false);
			if (x + 1 < 9)
			{
				x++;
			}
			ScreenManager::PrintArea(x, y, (cardChoice == 0) ? *cardManager.GetHand().front() : *cardManager.GetHand().back(), *this, COLOR_RED);
			if (tileManager.tile[y][x].GetType() == VOID_TILE)
			{
				ScreenManager::PrintTile(x * TILE_SIZE_X + TILE_POSITION_X, y * TILE_SIZE_Y + TILE_POSITION_Y, "   ", COLOR_RED);
			}
		}
		else if (!GetAsyncKeyState(VK_RIGHT))
		{
			keydown_right = false;
		}
		if (GetAsyncKeyState(VK_SPACE) && keydown_space == false)
		{
			keydown_space = true;
			UseCard(x, y, (cardChoice == 0) ? *cardManager.GetHand().front() : *cardManager.GetHand().back());
			cardManager.playerSelect(cardChoice + 1);
			ScreenManager::PrintInGame(*this);
			break;
		}
		else if (!GetAsyncKeyState(VK_SPACE))
		{
			keydown_space = false;
		}
		if (GetAsyncKeyState(VK_1) && keydown_1 == false)
		{
			keydown_1 = true;
			ScreenManager::PrintArea(x, y, (cardChoice == 0) ? *cardManager.GetHand().front() : *cardManager.GetHand().back(), *this, COLOR_WHITE, false);
			cardChoice = 0;
			ScreenManager::PrintArea(x, y, (cardChoice == 0) ? *cardManager.GetHand().front() : *cardManager.GetHand().back(), *this, COLOR_RED);
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
			ScreenManager::PrintArea(x, y, (cardChoice == 0) ? *cardManager.GetHand().front() : *cardManager.GetHand().back(), *this, COLOR_WHITE, false);
			cardChoice = 1;
			ScreenManager::PrintArea(x, y, (cardChoice == 0) ? *cardManager.GetHand().front() : *cardManager.GetHand().back(), *this, COLOR_RED);
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
	int temp;
	for (int i = 0; i < card.GetArea().size(); i++)
	{
		if (x + card.GetArea()[i].x < 0 || x + card.GetArea()[i].x > 8 || y + card.GetArea()[i].y < 0 || y + card.GetArea()[i].y > 8)
		{
			continue;
		}
		temp = rand() % 100 + 1;
		if (temp <= card.GetArea()[i].probability && tileManager.tile[y + card.GetArea()[i].y][x + card.GetArea()[i].x].GetType() != VOID_TILE)
		{
			tileManager.SetTile(y + card.GetArea()[i].y, x + card.GetArea()[i].x, false);
		}
		else if(tileManager.tile[y + card.GetArea()[i].y][x + card.GetArea()[i].x].GetType() == NORMAL_TILE)
		{
			ScreenManager::PrintTile((x + card.GetArea()[i].x) * TILE_SIZE_X + TILE_POSITION_X, (y + card.GetArea()[i].y) * TILE_SIZE_Y + TILE_POSITION_Y, "   ", COLOR_WHITE);
		}
		else if (tileManager.tile[y + card.GetArea()[i].y][x + card.GetArea()[i].x].GetType() == SPECIAL_TILE)
		{
			ScreenManager::PrintTile((x + card.GetArea()[i].x) * TILE_SIZE_X + TILE_POSITION_X, (y + card.GetArea()[i].y) * TILE_SIZE_Y + TILE_POSITION_Y, "   ", COLOR_PURPLE);
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
