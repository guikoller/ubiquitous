#pragma once

#include "Tilemap.h"

class SecondTileMap :
    public TileMap
{
private:
    void initTextures();
public:
    SecondTileMap();
    ~SecondTileMap();

    virtual void createMap();
};