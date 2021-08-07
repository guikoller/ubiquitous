#include "Player.h"

//IMITIALIZER FUNCTIONS
void Player::initVariables() {

}
void Player::initComponents() {

}

//CONSTRUCTORS DESTRUCTORS
Player::Player(float x, float y, sf::Texture* texture) {
	initVariables();
	initComponents();
	
	createSprite(texture);
	setPosition(x, y);
}
Player::~Player() {

}


