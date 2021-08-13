#pragma once
#include "Entity.h"

class Portal : virtual public Entity {
private:
	void initVariables();
	void initComponents();
public:
	Portal(float x, float y, sf::Texture& texture_sheet);
	virtual ~Portal();
	void update(const float& dt);
};

