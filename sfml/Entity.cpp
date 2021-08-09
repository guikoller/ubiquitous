#include "Entity.h"
void Entity::initVariables() {
	movementComponent = NULL;
}

Entity::Entity() {
	initVariables();
}

Entity::~Entity() {
	delete movementComponent;
	delete animationComponent;
}

void Entity::setTexture(sf::Texture& texture) {
	this->sprite.setTexture(texture);
}

void Entity::createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration) {
	this->movementComponent = new MovementComponent(this->sprite, maxVelocity, acceleration, deceleration);
}

void Entity::createAnimationComponent( sf::Texture& texture_sheet) {
	animationComponent = new AnimationComponent(this->sprite, texture_sheet);
}

void Entity::setPosition(const float pos_x, const float pos_y) {
	sprite.setPosition(pos_x, pos_y);	
}
void Entity::setSPriteScale(sf::Vector2f scale) {
	this->sprite.setScale(scale);
}
void Entity::move(const float& dt, const float x, const float y) {
	if (movementComponent){
		this->movementComponent->move(dt, x, y);
	}	
}


void Entity::update(const float& dt) {
	
}

void Entity::render(sf::RenderTarget& target) {
	target.draw(sprite);		
}