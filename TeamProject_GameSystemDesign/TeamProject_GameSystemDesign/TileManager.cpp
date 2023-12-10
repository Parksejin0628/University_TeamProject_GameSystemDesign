#include "TileManager.h"

void TileManager::initTile(int stageIndex)
{
  for (int y = 0; y < ROW; y++)
  {
    for (int x = 0; x < COL; x++)
    {
      tile[y][x].destory;
    }
  }
}

void TileManager::SetTile(int y, int x, TileType type)
{
  if (y >= 0 && y < ROW && x >= 0 && x < COL)
  {
    if (type == VOID_TILE)
    {
      tile[y][x].Destory;
    }
    else
    {
      tile[y][x].Create(type);
    }
  }
}

