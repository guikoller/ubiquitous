#pragma once
#include "Entity.h"
namespace Entity {
	namespace Enemy {
		class Bunny : virtual public Entity {
		private:
			void initVariables();
			void initComponents();
		public:
			Bunny(float x, float y, sf::Texture& texture_sheet);
			virtual ~Bunny();
			void update(const float& dt);
			void saveBunny();
			virtual void save();
		};
	}
}