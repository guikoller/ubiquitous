#include "Entity.h"
void Entity::initVariables() {
	movementSpeed = 100.f;
	this->sprite = NULL;
	this->texture = NULL;
}

Entity::Entity() {
	initVariables();
}

Entity::~Entity() {
	delete this->sprite;
}


void Entity::setPosition(const float pos_x, const float pos_y) {
	if (sprite){
		sprite->setPosition(pos_x, pos_y);
	}
}
void Entity::move(const float& dt, const float x, const float y) {
	if (sprite){
		sprite->move(x * movementSpeed * dt, y * movementSpeed * dt);
	}	
}
void Entity::createSprite(sf::Texture* texture) {
	this->texture = texture;
	this->sprite = new sf::Sprite(*this->texture);
	this->sprite->setTexture(*this->texture);
}

void Entity::update(const float& dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		move(dt, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		move(dt, 1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		move(dt, 0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		move(dt, 0.f, 1.f);
}

void Entity::render(sf::RenderTarget& target) {
	if (sprite) {
		target.draw(*sprite);
	}		
}