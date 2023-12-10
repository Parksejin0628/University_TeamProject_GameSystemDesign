#pragma once
#include "ProgramBase.h"

class Tile
{
private:
  int x, y;
  TileType type;

public:
  Tile(){}

  Tile(int x, int y, TileType type) : x(x), y(y), type(type) {}

  bool CanInteract();

  void Create(TileType type);

  void Destory();

  TileType GetType();
};