#include "Player.h"

//IMITIALIZER FUNCTIONS
void Player::initVariables() {

}
void Player::initComponents() {
	createMovementComponent(400.f, 10.f,2.f);
}

//CONSTRUCTORS DESTRUCTORS
Player::Player(float x, float y, sf::Texture& texture) {
	initVariables();
	initComponents();
	
	setTexture(texture);
	setPosition(x, y);
}
Player::~Player() {

}


