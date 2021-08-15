#pragma once
#include "Entity.h"
namespace Entity {
	namespace Obstacle {
		class Bullet : virtual public Entity {
		private:
			void initVariables();
			void initComponents();
		public:
			Bullet(float x, float y, sf::Texture& texture_sheet);
			virtual ~Bullet();
			void update(const float& dt);
			void saveBullet();
			virtual void save();
		};
	}
}