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

enum movement_states { IDLE = 0, MOVING, MOVING_LEFT, MOVING_RIGHT, MOVING_UP, MOVING_DOWN };

namespace Component {
	class MovementComponent {
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


		const bool getState(const short unsigned state) const;

		void stopVelocity();
		void stopVelocityX();
		void stopVelocityY();
		void gravity(const float& dt);

		void move(const float& dt, const float dir_x, const float dir_y);
		void update(const float& dt);
	};
}