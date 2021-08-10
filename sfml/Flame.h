#pragma once
#include "Entity.h"

class Flame : public Entity {
private:
	void initVariables();
	void initComponents();
public:
	Flame(float x, float y, sf::Texture& texture_sheet);
	virtual ~Flame();
	void update(const float dt);
};

