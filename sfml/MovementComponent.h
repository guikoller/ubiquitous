#pragma once

#include <stdlib.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <stack>
#include <map>
#include <vector>
#include <string.h>
#include <fstream>
#include <sstream>

#include "Button.h"

class MovementComponent{
private:
	sf::Sprite& sprite;

	float maxVelocity;
	float acceleration;
	float deceleration;
	
	sf::Vector2f velocity;


	void decelerateX();
	void decelerateY();
public:
	MovementComponent(sf::Sprite& sprite, const float maxVelocity, const float acceleration, const float deceleration);
	virtual ~MovementComponent();

	const sf::Vector2f& getVelocity()const;

	const bool idle()const;
	const bool moving()const;
	const bool movingLeft()const;
	const bool movingRight()const;

	void move(const float& dt, const float dir_x, const float dir_y);
	void update(const float& dt);
};

