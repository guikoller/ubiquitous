#include "Bullet.h"
namespace Entity {
	namespace Obstacle {
		//INITIALIZER FUNCTIONS
		void Bullet::initVariables() {
			setID(7);
		}
		void Bullet::initComponents() {

		}

		//CONSTRUCTORS DESTRUCTORS
		Bullet::Bullet(float x, float y, sf::Texture& texture_sheet) {
			initVariables();

			setPosition(x, y);

			createHitboxComponent(this->sprite, 18, 18, 24, 24);
			createMovementComponent(1000.f, 20.f, 7.f);

			this->sprite.setTexture(texture_sheet);

			setSPriteScale(sf::Vector2f(3.f, 3.f));


		}
		Bullet::~Bullet() {

		}
		void Bullet::update(const float& dt) {
			this->movementComponent->update(dt);

			move(dt, 100, 0);

			this->hitboxComponent->update();
		}

		void Bullet::saveBullet()
		{
			file.open("Saves/save.txt", std::ios::app);
			file << this->hitboxComponent->getPosition().x << "\n";
			file << this->hitboxComponent->getPosition().y << "\n";
			file.close();
		}

		void Bullet::save()
		{
			saveBullet();
		}
	}
}