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
      for (int i = 0; i < 3; ++i)
      {
        int randomY = std::rand() % ROW;
        int randomX = std::rand() % COL;

      // 이미 타일이 존재하지 않는 경우에만 생성
        if (tile[randomY][randomX].GetType() != NORMAL_TILE)
        {
          tile[randomY][randomX].Create(NORMAL_TILE);
          tmp.Destory();
        }
      }
    }
  }
}