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