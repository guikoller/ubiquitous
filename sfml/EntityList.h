#pragma once

#include "List.h"

#include "Player.h"

#include "Enemy.h"
#include "Bunny.h"
#include "Plant.h"

#include "Portal.h"
#include "Flame.h"
#include "Box.h"


class EntityList{
private:
	List<Entity*> entities;

public:
	EntityList();
	~EntityList();

    using iterator = List<Entity*>::iterator;

    void add(Entity* ent);
    void remove(Entity* ent);
    void move(const float& dt);
    
    void destroy();

    

    void update(const float& dt);
    void render(sf::RenderTarget& target);

    iterator begin();
    iterator end();
};



