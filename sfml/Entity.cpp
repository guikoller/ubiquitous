#include "Entity.h"
namespace Entity {
	void Entity::initVariables() {
		movementComponent = NULL;
		animationComponent = NULL;
		hitboxComponent = NULL;
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
		this->movementComponent = new Component::MovementComponent(this->sprite, maxVelocity, acceleration, deceleration);
	}

	void Entity::createAnimationComponent(sf::Texture& texture_sheet) {
		this->animationComponent = new Component::AnimationComponent(this->sprite, texture_sheet);
	}

	void Entity::createHitboxComponent(sf::Sprite& sprite,
		float offset_x, float offset_y,
		float width, float height)
	{
		this->hitboxComponent = new Component::HitboxComponent(sprite, offset_x, offset_y, width, height);
	}

	void Entity::setPosition(const float pos_x, const float pos_y) {
		sprite.setPosition(pos_x, pos_y);
	}
	void Entity::setSPriteScale(sf::Vector2f scale) {
		this->sprite.setScale(scale);
	}
	void Entity::move(const float& dt, const float x, const float y) {
		if (movementComponent) {
			this->movementComponent->move(dt, x, y);
		}
	}

	void Entity::update(const float& dt)
	{
	}

	void Entity::render(sf::RenderTarget& target) {
		target.draw(sprite);
		if (this->hitboxComponent)
			hitboxComponent->render(target);
	}

	void Entity::setID(const int id)
	{
		this->id = id;
	}


	const int Entity::getID()const {
		return id;
	}

	bool Entity::intersects(const sf::FloatRect& frect) {
		if (hitboxComponent)
			return hitboxComponent->intersects(frect);
	}

	const sf::FloatRect Entity::getGlobalBounds() const {
		if (hitboxComponent)
			return hitboxComponent->getGlobalBounds();
	}
}