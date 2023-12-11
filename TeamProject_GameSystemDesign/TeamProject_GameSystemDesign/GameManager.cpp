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

void GameManager::ReadFromFile(){
	
	ifstream fin("map.txt");

	if(!fin) { 
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
	static int x = 4;
	static int y = 4;
	bool keydown_up = false;
	bool keydown_down = false;
	bool keydown_left = false;
	bool keydown_right = false;

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
	}
}
