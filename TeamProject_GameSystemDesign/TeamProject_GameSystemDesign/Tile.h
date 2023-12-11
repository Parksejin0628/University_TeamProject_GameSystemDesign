#pragma once
#include "ProgramBase.h"

class Tile
{
private:
  int x, y;
  int type;

public:
  Tile(){}

  Tile(int x, int y, int type) : x(x), y(y), type(type) {}

  bool CanInteract();

  void Create(int type);

  void Destory();

  int GetType();
};