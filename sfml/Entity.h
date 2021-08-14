#pragma once
#include "MovementComponent.h"
#include "AnimationComponent.h"
#include "HitboxComponent.h"

class Entity{
private:
	void initVariables();

public:
	int id;
	sf::Sprite sprite;
	
	MovementComponent* movementComponent;
	AnimationComponent* animationComponent;
	HitboxComponent* hitboxComponent;

	Entity();
	virtual ~Entity();

	//Components functions
	void setTexture(sf::Texture& texture);
	void createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration);
	void createAnimationComponent(sf::Texture& texture_sheet);
	void createHitboxComponent(sf::Sprite& sprite,float offset_x, float offset_y, float width, float height);

	//Accersor
	const int getID()const {
		return id;
	}

	bool intersects(const sf::FloatRect& frect) {
		if (hitboxComponent)
			return hitboxComponent->intersects(frect);
	}

	const sf::FloatRect getGlobalBounds() const {
		if(hitboxComponent)
			return hitboxComponent->getGlobalBounds();
	}

	//Functions
	virtual void setPosition(const float pos_x, const float pos_y);
	virtual void setSPriteScale(sf::Vector2f scale);
	virtual void move(const float& dt, const float x, const float y);
	void setID(const int id);
	
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget& target);
};

