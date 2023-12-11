#include "TileManager.h"

TileManager::TileManager()
{
  // Initialize TileManager with empty tiles
  for (int y = 0; y < ROW; y++)
  {
    for (int x = 0; x < COL; x++)
    {
      tile[y][x] = Tile(y, x, VOID_TILE);
    }
  }
  ReadFile();
}

void TileManager::InitTile(int stageIndex)
{
  for (int y = 0; y < stage[stageIndex].size(); y++)
  {
    for (int x = 0; x < stage[stageIndex][y].length(); x++)
    {
        int value = stoi(stage[stageIndex][y].substr(x, 1));
        tile[y][x].Create(value);
    }
  }
}

void TileManager::ReadFile()
	{
	ifstream fin("map.txt");
	if (!fin) {
		cout << "words.txt 파일을 열 수 없습니다" << endl;
		return; // 열기 오류
	}

	string line;

	while (getline(fin, line)) { // fin 파일에서 한 라인 읽기
		if (line.empty())
		{
			// 빈 줄이 나오면 새로운 스테이지 생성
			if (!stageData.empty())
			{
				stage.emplace_back(stageData);
				stageData.clear();
			}
		}
		else
		{
			stageData.push_back(line);
		}
	}
	fin.close();
}

vector<string> TileManager::GetStage(int stageIndex){
  return stage[stageIndex];
}

void TileManager::SetTile(int y, int x, bool cure)
{
  if (y >= 0 && y < ROW && x >= 0 && x < COL)
  {
	if (!cure){
		if (tile[y][x].GetType() == SPECIAL_TILE) {
			for (int i = 0; i < 3;)
			{
				int randomY = std::rand() % ROW;
				int randomX = std::rand() % COL;

				if (tile[randomY][randomX].GetType() == VOID_TILE)
				{
					tile[randomY][randomX].Create(NORMAL_TILE);
					i++;
				}
			}
		}
	}
	tile[y][x].Destory();
  }
}