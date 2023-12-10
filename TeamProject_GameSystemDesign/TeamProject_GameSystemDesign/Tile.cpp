#include "tile.h"

Tile::Tile(int x, int y, TileType type) : x(x), y(y), type(type)
{
    this->x = x;
    this->y = y;
    this->type = type;
}

void Tile::Create(TileType type)
{
    this->type = type;
}

void Tile::Destory()
{
    this->type = VOID_TILE;
}

bool Tile::CanInteract()
{
    if (this->type <= 0)
    {
        return false;
    }
    return true;
}

TileType Tile::GetType()
{
    return this->type;
}