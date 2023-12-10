#include "tile.h"

void Tile::Create(TileType type)
{
    this->type = type;
}

void Tile::Destory()
{
    this->type = VOID_TILE;
}

bool Interact(TileType tile)
{
    if (tile <= 0)
    {
        return false;
    }
    return true;
}