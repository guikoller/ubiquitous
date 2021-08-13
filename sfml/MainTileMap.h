#pragma once
#include "Tilemap.h"
class MainTileMap :
    public TileMap
{
private:
    void initTextures();
public:
    MainTileMap();
    ~MainTileMap();
    
    void createMap();
};

