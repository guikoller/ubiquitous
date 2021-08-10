#include "Flame.h"

//INITIALIZER FUNCTIONS
void Flame::initVariables() {

}
void Flame::initComponents() {

}

//CONSTRUCTORS DESTRUCTORS
Flame::Flame(float x, float y, sf::Texture& texture_sheet) {
	initVariables();

	setPosition(x, y);

	createHitboxComponent(this->sprite, 35, 35, 60, 60);
	createAnimationComponent(texture_sheet);

	setSPriteScale(sf::Vector2f(2.f, 2.f));

	this->animationComponent->addAnimation("IDDLE", 12.f, 0, 0, 3, 0, 64, 64);

}
Flame::~Flame() {

}
void Flame::update(const float dt) {

	this->animationComponent->play("IDDLE", dt, true);

	this->hitboxComponent->update();

}


