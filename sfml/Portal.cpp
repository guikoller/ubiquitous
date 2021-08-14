#include "Portal.h"

//INITIALIZER FUNCTIONS
void Portal::initVariables() {
	setID(3);
}
void Portal::initComponents() {

}

//CONSTRUCTORS DESTRUCTORS
Portal::Portal(float x, float y, sf::Texture& texture_sheet) {
	initVariables();

	setPosition(x, y);

	createHitboxComponent(this->sprite, 73, 45, 43, 128);
	createAnimationComponent(texture_sheet);

	setSPriteScale(sf::Vector2f(3.f, 3.f));

	this->animationComponent->addAnimation("IDDLE", 12.f, 0, 0, 7, 0, 64, 64);

}
Portal::~Portal() {

}
void Portal::update(const float& dt) {
	
	this->animationComponent->play("IDDLE", dt, true);

	this->hitboxComponent->update();

}


