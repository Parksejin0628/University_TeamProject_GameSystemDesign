#pragma once
#include "ProgramBase.h"

class Tile
{
private:
  int x, y;
  int type;

public:
  Tile() : type(VOID_TILE), x(0), y(0) {  }

  Tile(int x, int y, int type) : x(x), y(y), type(type) {}

  bool CanInteract();

  void Create(int type);

  void Destory();

  int GetType();
};