#include "tile.h"

void Tile::Create(Tiletype type)
{
    this->type = type;
}

void Tile::Destory()
{
    this->type = VOID_TILE;
}

bool Interact(Tiletype tile)
{
    if (tile <= 0)
    {
        return false;
    }
    return true;
}