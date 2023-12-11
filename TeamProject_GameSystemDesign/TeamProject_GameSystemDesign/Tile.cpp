#include "tile.h"
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