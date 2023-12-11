#include "tile.h"

void Tile::Create(int type)
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

int Tile::GetType()
{
    return this->type;
}