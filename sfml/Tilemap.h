#pragma once
#include <vector>
#include "Tile.h"
#include "Player.h"
class TileMap
{
protected:
    std::vector< std::vector <Tile*>> map;
    
    std::map<std::string, sf::Texture> sprites;
    sf::Texture texture;
    
    int height;
    int width;

    void initTextures();
    
public:
    TileMap();
    virtual ~TileMap();

    //Acessores
    
    const bool isSolid(int x, int y) const;

    virtual void createMap();
    void updateCollision(Player *player,const float &dt);
    void render(sf::RenderTarget& target);
};