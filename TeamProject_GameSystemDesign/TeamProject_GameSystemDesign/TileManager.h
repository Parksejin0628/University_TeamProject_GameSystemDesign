#pragma once
#include "Tile.h"

class TileManager
{
private:
  int x, y;
  Tile tile[9][9];
  vector<Tile> voidarr;

public:
  TileManager();
  void InitTile(int stageIndex) {} // 스테이지
  void SetTile(int y, int x) {} 
};