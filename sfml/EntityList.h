#pragma once
#include "Entity.h"
#include "List.hpp"
#include "State.h"

class EntityList{
private:
	List<Entity*> entities;

public:
	EntityList();
	~EntityList();

    using iterator = List<Entity*>::iterator;

    void add(Entity* ent);
    void remove(Entity* ent);

    
    void initEntities(State *state);
    
    void destroy();

    iterator begin();
    iterator end();

    void update(const float& dt);
    void render(sf::RenderTarget& target);
};



