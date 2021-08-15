#pragma once
#include "Entity.h"
namespace Entity {
	namespace Obstacle {
		class Flame : virtual public Entity {
		private:
			void initVariables();
			void initComponents();
		public:
			Flame(float x, float y, sf::Texture& texture_sheet);
			virtual ~Flame();
			void update(const float& dt);
			void saveFlame();
			virtual void save();
		};
	}
}