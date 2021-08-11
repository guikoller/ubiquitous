#pragma once
#include "Entity.h"
#include "List.hpp"

class EntityList{
private:
	List<Entity*> entities;

public:
	EntityList();
	~EntityList();

    using iterator = List<Entity*>::iterator;

    void add(Entity* ent);
    void remove(Entity* ent);

    
    //void initializeAll(Levels::Level* level);
    void destroy();

    iterator begin();
    iterator end();

    void update(const float& dt);
    void render(sf::RenderTarget& target);
};



