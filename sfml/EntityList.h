#pragma once

//#include "List.h"

#include "Player.h"

#include "Enemy.h"
#include "Bunny.h"
#include "Plant.h"

#include "Portal.h"
#include "Flame.h"
#include "Box.h"


class EntityList {
private:
    std::vector<Entity*> entities;

public:
    EntityList();
    ~EntityList();



    void add(Entity* ent);
    void remove(Entity* ent);



    void destroy();

    const int length()const;

    Entity* getElement(const int pos);

    void update(const float& dt);
    void render(sf::RenderTarget& target);


};