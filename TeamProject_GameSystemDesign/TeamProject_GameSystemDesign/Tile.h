#pragma once
#include "ProgramBase.h"

class Tile
{
protected:
  int x, y;
  TileType type;

public:
  Tile(int x, int y, TileType type) : x(x), y(y)
  {
    this->type = type;
  }
  bool CanInteract(Tiletype type);

  void Create(Tiletype type);

  void Destory();
};