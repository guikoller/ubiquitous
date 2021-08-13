#pragma once
#include "Entity.h"

class Box : virtual public Entity {
private:
	void initVariables();
	void initComponents();
public:
	Box(float x, float y, sf::Texture& texture_sheet);
	virtual ~Box();
	void update(const float& dt);
};

