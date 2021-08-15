#pragma once
#include "Tilemap.h"
namespace Entity {
    class MainTileMap :
        public TileMap
    {
    private:
        void initTextures();
    public:
        MainTileMap();
        ~MainTileMap();

        virtual void createMap();
    };
}