#include "Box.h"

//INITIALIZER FUNCTIONS
void Box::initVariables() {

}
void Box::initComponents() {

}

//CONSTRUCTORS DESTRUCTORS
Box::Box(float x, float y, sf::Texture& texture_sheet) {
	initVariables();

	setPosition(x, y);

	createHitboxComponent(this->sprite, 73, 45, 43, 128);
	createAnimationComponent(texture_sheet);

	setSPriteScale(sf::Vector2f(3.f, 3.f));

	this->animationComponent->addAnimation("IDDLE", 12.f, 0, 0, 7, 0, 64, 64);

}
Box::~Box() {

}
void Box::update(const float dt) {

	this->animationComponent->play("IDDLE", dt, true);

	this->hitboxComponent->update();

}


