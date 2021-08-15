#pragma once
#include "Entity.h"
namespace Entity {
	namespace Obstacle {
		class Portal : virtual public Entity {
		private:
			void initVariables();
			void initComponents();
		public:
			Portal(float x, float y, sf::Texture& texture_sheet);
			virtual ~Portal();
			void update(const float& dt);
			void savePortal();
			virtual void save();
		};
	}
}
