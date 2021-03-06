#pragma once
#include "Entity.h"
namespace Entity {
	namespace Obstacle {
		class Box : virtual public Entity {
		private:
			void initVariables();
			void initComponents();
		public:
			Box(float x, float y, sf::Texture& texture_sheet);
			virtual ~Box();
			void update(const float& dt);
			void saveBox();
			virtual void save();
		};
	}
}