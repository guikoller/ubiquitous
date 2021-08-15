#pragma once
#include "Entity.h"

class Player :  public Entity{
private:
	int life;
	int score;
	void initVariables();
	void initComponents();
public:
	Player(float x, float y, sf::Texture& texture_sheet);
	virtual ~Player();
	virtual void update(const float& dt);
	void operator++(int num) {
		score + num;
	}
	void operator--(int num) {
		life - num;
	}
	void savePlayer();
	virtual void save();
};

