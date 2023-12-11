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
  for (int y = 0; y < ROW; y++)
  {
    for (int x = 0; x < COL; x++)
    {
      tile[y][x].Destory();
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

void TileManager::SetTile(int y, int x)
{
  if (y >= 0 && y < ROW && x >= 0 && x < COL)
  {
    Tile tmp;
    tmp = tile[y][x];
    if (tmp.GetType() == VOID_TILE)
    {
      tmp.Create(NORMAL_TILE);
    }
    else
    {
      if(tmp.GetType() == SPECIAL_TILE)
      {
        // 랜덤으로 3개의 노말 타일 생성
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
      tmp.Destory();
    }
  }
}