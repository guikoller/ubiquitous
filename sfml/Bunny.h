#pragma once
#include "Entity.h"
class Bunny : public Entity {
private:
	void initVariables();
	void initComponents();
public:
	Bunny(float x, float y, sf::Texture& texture_sheet);
	virtual ~Bunny();
	void update(const float dt);
};
