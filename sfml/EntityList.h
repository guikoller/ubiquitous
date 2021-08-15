#pragma once

//#include "List.h"

#include "Player.h"

#include "Enemy.h"
#include "Bunny.h"
#include "Plant.h"

#include "Portal.h"
#include "Flame.h"
#include "Box.h"
#include "Bullet.h"


class EntityList {
private:
    std::vector<Entity::Entity*> entities;

public:
    EntityList();
    ~EntityList();



    void add(Entity::Entity* ent);
    void remove(const int pos);



    void destroy();

    const int length()const;

    Entity::Entity* getElement(int pos);

    void update(const float& dt);
    void render(sf::RenderTarget& target);


};