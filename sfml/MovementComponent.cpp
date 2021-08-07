#include "MovementComponent.h"

//INITIALIZERS



//CONTRUCTOR DESTRUCTOR
MovementComponent::MovementComponent(const float maxVelocity) {
	this->maxVelocity = maxVelocity;
}

MovementComponent::~MovementComponent() {
}


const sf::Vector2f& MovementComponent::getVelocity()const {

}
//FUNC

void MovementComponent::move(const float &dt, const float dir_x, const float dir_y) {
	velocity.x = maxVelocity * dir_x;
	velocity.y = maxVelocity * dir_y;
}
void MovementComponent::update(const float& dt) {

}