#include "Plant.h"
namespace Entity {
	namespace Enemy {
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

			createHitboxComponent(this->sprite, 0, 3, 50, 80);
			createMovementComponent(300.f, 7.f, 4.f);
			createAnimationComponent(texture_sheet);

			setSPriteScale(sf::Vector2f(2.f, 2.f));

			this->animationComponent->addAnimation("IDDLE", 8.f, 0, 0, 7, 0, 44, 42);

		}
		Plant::~Plant() {

		}
		void Plant::update(const float& dt) {
			this->movementComponent->update(dt);
			this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2.f, 0.f);
			setSPriteScale(sf::Vector2f(-2.f, 2.f));

			this->hitboxComponent->update();
		}

		void Plant::savePlant()
		{
			file.open("Saves/save.txt", std::ios::app);
			file << this->hitboxComponent->getPosition().x << "\n";
			file << this->hitboxComponent->getPosition().y << "\n";
			file.close();
		}

		void Plant::save()
		{
			savePlant();
		}
	}
}



