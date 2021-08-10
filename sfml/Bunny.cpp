#include "Bunny.h"

//INITIALIZER FUNCTIONS
void Bunny::initVariables() {

}
void Bunny::initComponents() {

}

//CONSTRUCTORS DESTRUCTORS
Bunny::Bunny(float x, float y, sf::Texture& texture_sheet) {
	initVariables();

	setPosition(x, y);

	createHitboxComponent(this->sprite, 20, 20, 64, 110);
	createMovementComponent(300.f, 7.f, 4.f);
	createAnimationComponent(texture_sheet);

	setSPriteScale(sf::Vector2f(3.f, 3.f));

	this->animationComponent->addAnimation("IDDLE", 8.f, 0, 0, 7, 0, 34, 44);
	this->animationComponent->addAnimation("RUN", 6.f, 1, 1, 11, 1, 34, 44);

}
Bunny::~Bunny() {

}
void Bunny::update(const float dt) {
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


