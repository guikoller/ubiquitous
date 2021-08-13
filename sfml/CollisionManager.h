#pragma once

#include "EntityList.h"

class CollisionManager{
private:
	Entity *ent;
	EntityList *list;
public:
	CollisionManager();
	~CollisionManager();
	void add(Entity* ent, EntityList* list);
	void update(const float& dt);
};




