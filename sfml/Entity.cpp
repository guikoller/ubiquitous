#include "Entity.h"
void Entity::initVariables() {
	movementComponent = NULL;
}

Entity::Entity() {
	initVariables();
}

Entity::~Entity() {
	delete movementComponent;
}

void Entity::setTexture(sf::Texture& texture) {
	this->sprite.setTexture(texture);
}

void Entity::createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration) {
	this->movementComponent = new MovementComponent(sprite, maxVelocity, acceleration, deceleration);
}

void Entity::setPosition(const float pos_x, const float pos_y) {
	sprite.setPosition(pos_x, pos_y);	
}
void Entity::move(const float& dt, const float x, const float y) {
	if (movementComponent){
		this->movementComponent->move(dt, x, y);
	}	
}


void Entity::update(const float& dt) {
	if (movementComponent)
		this->movementComponent->update(dt);
}

void Entity::render(sf::RenderTarget& target) {
	target.draw(sprite);		
}