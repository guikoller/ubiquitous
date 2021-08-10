#pragma once
#include "MovementComponent.h"
#include "AnimationComponent.h"
#include "HitboxComponent.h"

class Entity{
private:
	void initVariables();

protected:
	sf::Sprite sprite;
	
	MovementComponent* movementComponent;
	AnimationComponent* animationComponent;
	HitboxComponent* hitboxComponent;
public:
	Entity();
	virtual ~Entity();

	//Components functions
	void setTexture(sf::Texture& texture);
	void createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration);
	void createAnimationComponent(sf::Texture& texture_sheet);
	void createHitboxComponent(sf::Sprite& sprite,float offset_x, float offset_y, float width, float height);


	//Functions
	virtual void setPosition(const float pos_x, const float pos_y);
	virtual void setSPriteScale(sf::Vector2f scale);
	virtual void move(const float& dt, const float x, const float y);
	
	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget& target);
};

