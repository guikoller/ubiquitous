#pragma once
#include "Entity.h"
namespace Entity {
	namespace Enemy {
		class Plant : virtual public Entity {
		private:
			void initVariables();
			void initComponents();
		public:
			Plant(float x, float y, sf::Texture& texture_sheet);
			virtual ~Plant();
			void update(const float& dt);
			void savePlant();
			virtual void save();
		};
	}
}

