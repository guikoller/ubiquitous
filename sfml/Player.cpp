#include "Player.h"

//INITIALIZER FUNCTIONS
void Player::initVariables() {

}
void Player::initComponents() {
	
}

//CONSTRUCTORS DESTRUCTORS
Player::Player(float x, float y, sf::Texture& texture_sheet) {
	initVariables();
	
	setPosition(x, y);
	
	createHitboxComponent(this->sprite, 17, 14, 64, 80);
	createMovementComponent(500.f, 10.f, 7.f);
	createAnimationComponent(texture_sheet);
	
	setSPriteScale(sf::Vector2f(3.f,3.f));

	this->animationComponent->addAnimation("IDDLE", 8.f, 1, 0, 10, 0, 32, 32);
	this->animationComponent->addAnimation("RUN", 5.f, 0, 1, 11, 1, 32, 32);
	
}
Player::~Player() {

}
void Player::update(const float& dt) {
	this->movementComponent->update(dt);
	

	if (movementComponent->getState(IDLE)){
		this->animationComponent->play("IDDLE", dt, false);
	}
	else if(movementComponent->getState(MOVING_RIGHT)){
		setSPriteScale(sf::Vector2f(3.f, 3.f));
		this->sprite.setOrigin(0.f, 0.f);
		this->animationComponent->play("RUN", dt, false);
	}
	else if (movementComponent->getState(MOVING_LEFT)) {
		setSPriteScale(sf::Vector2f(-3.f, 3.f));
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 3.f, 0.f);
		this->animationComponent->play("RUN", dt, false);
	}


	this->hitboxComponent->update();
	
}


