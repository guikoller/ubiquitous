#pragma once
#include "Tilemap.h"
namespace Entity {
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
}