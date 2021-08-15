#include "Box.h"
namespace Entity {
	namespace Obstacle {
		//INITIALIZER FUNCTIONS
		void Box::initVariables() {
			setID(1);
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
		void Box::update(const float& dt) {



			this->hitboxComponent->update();

		}

		void Box::saveBox()
		{
			file.open("Saves/save.txt", std::ios::app);
			file << this->hitboxComponent->getPosition().x << "\n";
			file << this->hitboxComponent->getPosition().y << "\n";
			file.close();
		}

		void Box::save()
		{
			saveBox();
		}
	}
}