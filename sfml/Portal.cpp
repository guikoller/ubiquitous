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

	createHitboxComponent(this->sprite, 48, 30, 28, 85);
	createAnimationComponent(texture_sheet);

	setSPriteScale(sf::Vector2f(2.f, 2.f));

	this->animationComponent->addAnimation("IDDLE", 12.f, 0, 0, 7, 0, 64, 64);

}
Portal::~Portal() {

}
void Portal::update(const float& dt) {
	
	this->animationComponent->play("IDDLE", dt, true);

	this->hitboxComponent->update();

}

void Portal::savePortal()
{
	file.open("Saves/save.txt", std::ios::app);
	file << this->hitboxComponent->getPosition().x << "\n";
	file << this->hitboxComponent->getPosition().y << "\n";
	file.close();
}

void Portal::save()
{
	savePortal();
}


