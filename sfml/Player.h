#pragma once
#include "Entity.h"
namespace Entity {
	namespace Player {
		class Player : public Entity {
		private:
			int life;
			int score;
			void initVariables();
			void initComponents();
		public:
			Player(float x, float y, sf::Texture& texture_sheet);
			virtual ~Player();
			virtual void update(const float& dt);

			void addLife(int num) {
				this->life += num;
			}
			const int getLife()const {
				return life;
			}
			void savePlayer();
			virtual void save();
		};
	}
}


