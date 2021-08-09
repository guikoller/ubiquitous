#include "MovementComponent.h"

//INITIALIZERS


//CONTRUCTOR DESTRUCTOR
MovementComponent::MovementComponent(sf::Sprite& sprite, const float maxVelocity, const float acceleration, float const deceleration)
	: sprite(sprite), maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration)
{

}

MovementComponent::~MovementComponent() {
}


const sf::Vector2f& MovementComponent::getVelocity()const {
	return velocity;
}

//FUNCTIONS
void MovementComponent::decelerateX(){
	if (velocity.x > 0.f) {

		if (velocity.x > maxVelocity)
			velocity.x = maxVelocity;

		velocity.x -= deceleration;
		if (velocity.x < 0.f)
			velocity.x = 0;

	}
	else if (velocity.x < 0.f) {

		if (velocity.x < -maxVelocity)
			velocity.x = -maxVelocity;

		velocity.x += deceleration;
		if (velocity.x > 0.f)
			velocity.x = 0;
	}
}

void MovementComponent::decelerateY() {
	if (velocity.y > 0.f) {

		if (velocity.y > maxVelocity)
			velocity.y = maxVelocity;

		velocity.y -= deceleration;
		if (velocity.y < 0.f)
			velocity.y = 0;

	}
	else if (velocity.y < 0.f) {

		if (velocity.y < -maxVelocity)
			velocity.y = -maxVelocity;

		velocity.y += deceleration;
		if (velocity.y > 0.f)
			velocity.y = 0;
	}

}

const bool MovementComponent::idle()const {
	if (velocity.x == 0)
		return true;

	return false;
}

void MovementComponent::move(const float &dt, const float dir_x, const float dir_y) {
	//ACCELERATION
	velocity.x += acceleration * dir_x;
	velocity.y += acceleration * dir_y;
}

void MovementComponent::update(const float& dt) {
	//DECELERATION
	decelerateX();
	decelerateY();

	sprite.move(velocity * dt);
}