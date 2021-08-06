#include "Entity.h"

Entity::Entity() {
	shape.setSize(sf::Vector2f(50.f, 50.f));
	movementSpeed = 100.f;
}
Entity::~Entity() {

}
void Entity::move(const float& dt, const float x, const float y) {
	this->shape.move(x * movementSpeed * dt, y * movementSpeed * dt);
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
	target.draw(this->shape);
}