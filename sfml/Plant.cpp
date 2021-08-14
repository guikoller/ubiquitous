#include "Plant.h"

//INITIALIZER FUNCTIONS
void Plant::initVariables() {
	setID(6);
}
void Plant::initComponents() {

}

//CONSTRUCTORS DESTRUCTORS
Plant::Plant(float x, float y, sf::Texture& texture_sheet) {
	initVariables();

	setPosition(x, y);

	createHitboxComponent(this->sprite, 25, 3, 50, 80);
	createMovementComponent(300.f, 7.f, 4.f);
	createAnimationComponent(texture_sheet);

	setSPriteScale(sf::Vector2f(2.f, 2.f));

	this->animationComponent->addAnimation("IDDLE", 8.f, 0, 0, 7, 0, 44, 42);

}
Plant::~Plant() {

}
void Plant::update(const float& dt) {
	this->movementComponent->update(dt);


	if (movementComponent->getState(IDLE)) {
		this->animationComponent->play("IDDLE", dt, false);
	}
	else if (movementComponent->getState(MOVING_LEFT)) {
		setSPriteScale(sf::Vector2f(3.f, 3.f));
		this->sprite.setOrigin(0.f, 0.f);
		this->animationComponent->play("RUN", dt, false);
	}
	else if (movementComponent->getState(MOVING_RIGHT)) {
		setSPriteScale(sf::Vector2f(-3.f, 3.f));
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 3.f, 0.f);
		this->animationComponent->play("RUN", dt, false);
	}


	this->hitboxComponent->update();

}


