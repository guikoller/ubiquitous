#include "Player.h"

//IMITIALIZER FUNCTIONS
void Player::initVariables() {

}
void Player::initComponents() {
	
}

//CONSTRUCTORS DESTRUCTORS
Player::Player(float x, float y, sf::Texture& texture_sheet) {
	initVariables();
	
	setPosition(x, y);

	createMovementComponent(500.f, 10.f, 7.f);
	createAnimationComponent(texture_sheet);
	setSPriteScale(sf::Vector2f(3.f,3.f));

	this->animationComponent->addAnimation("IDDLE", 10.f, 0, 0, 2, 0, 192, 192);
	
}
Player::~Player() {

}
void Player::update(const float dt) {
	this->movementComponent->update(dt);
	
	this->animationComponent->play("IDDLE", dt);
}


