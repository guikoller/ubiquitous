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
	float maxVelocity;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	sf::Vector2f deceleration;
public:
	MovementComponent(const float maxVelocity);
	virtual ~MovementComponent();

	const sf::Vector2f& getVelocity()const;

	void move(const float& dt, const float dir_x, const float dir_y);
	void update(const float& dt);
};

