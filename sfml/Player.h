#pragma once
#include "Entity.h"

class Player :  public Entity{
private:
	int life;
	void initVariables();
	void initComponents();
public:
	Player(float x, float y, sf::Texture& texture_sheet);
	virtual ~Player();
	virtual void update(const float& dt);
	void operator++(int num) {
		life + num;
	}
	void operator--(int num) {
		life - num;
	}
};

