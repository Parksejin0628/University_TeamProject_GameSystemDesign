#pragma once
#include"ProgramBase.h"
#include "Tile.h"

class TileManager
{
private:
  Tile tile[9][9];
  vector<Tile> voidarr;

public:
  TileManager(int rows = ROW, int cols = COL);
  void InitTile(int stageIndex) {} // 스테이지
  void SetTile(int y, int x, TileType type) {}
};