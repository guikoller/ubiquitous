#pragma once
#include "EntityList.h"

class CollisionManager{
private:
	Entity::Player::Player *ent;
	EntityList *list;
	sf::Clock clock;
public:
	CollisionManager();
	~CollisionManager();
	void add(Entity::Player::Player* ent, EntityList* list);
	void update(const float& dt);
};