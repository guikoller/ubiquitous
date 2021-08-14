#pragma once
#include <vector>
#include "Tile.h"
#include "Player.h"
class TileMap
{
protected:
    std::vector< std::vector <Tile*>> map;
    
    sf::Texture texture;
    
    int height;
    int width;

    virtual void initTextures();
    
public:
    TileMap();
    virtual ~TileMap();
    
    void deleteMap();

    //Acessores
    
    const bool isSolid(int x, int y) const;

    virtual void createMap() = 0;
    void updateCollision(Player* player, const float& dt);
    void render(sf::RenderTarget& target);
};