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

	createHitboxComponent(this->sprite, 0, 0, 64, 48);
	
	this->sprite.setTexture(texture_sheet);

	setSPriteScale(sf::Vector2f(3.f, 3.f));


}
Box::~Box() {

}
void Box::update(const float dt) {

	

	this->hitboxComponent->update();

}


