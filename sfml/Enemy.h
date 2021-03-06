#pragma once
#include "Entity.h"
namespace Entity {
	namespace Enemy {
		class Enemy : virtual public Entity {
		private:
			void initVariables();
			void initComponents();
		public:
			Enemy(float x, float y, sf::Texture& texture_sheet);
			virtual ~Enemy();
			void update(const float& dt);
			void saveEnemy();
			virtual void save();
		};
	}
}
