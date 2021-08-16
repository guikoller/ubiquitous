#include "SecondGameState.h"
namespace State {
	namespace GameState {
				
		void SecondGameState::initList() {
			for (int i = 0; i < 3; i++)
				entities.add(new Entity::Enemy::Enemy(0, 0, textures["ENEMY_SHEET"]));

			for (int i = 0; i < 3; i++)
				entities.add(new Entity::Enemy::Bunny(0, 0, textures["BUNNY_SHEET"]));


			for (int i = 0; i < 3; i++)
				entities.add(new Entity::Obstacle::Flame(0, 0, textures["FLAME_SHEET"]));

			for (int i = 0; i < 3; i++)
				entities.add(new Entity::Obstacle::Box(0, 0, textures["BOX"]));
		}
		
		void SecondGameState::initPositions() {

			std::srand((unsigned)std::time(0));

			float xpos;

			for (int i = 0; i < entities.length(); i++)
			{
				if (entities.getElement(i)->getID() == 1)//Box
				{
					std::vector<float> ypos = { 210, 530, 784 };

					int it = (rand() % 3);

					if (ypos.at(it) == 210) {
						xpos = (rand() % 1300);
						
						entities.getElement(i)->setPosition(xpos, ypos[it]);
					}
					else if (ypos.at(it) == 530) {
						xpos = (rand() % 1400) + 300;
						if (xpos > 1400)
							xpos = 1400;
						entities.getElement(i)->setPosition(xpos, ypos[it]);
					}
					else if (ypos.at(it) == 784) {
						xpos = (rand() % 1000) + 500;
						entities.getElement(i)->setPosition(xpos, ypos[it]);
					}
				}
				if (entities.getElement(i)->getID() == 2)//Flame
				{
					std::vector<float> ypos = { 160, 480, 740 };

					int it = (rand() % 3);

					if (ypos.at(it) == 160) {
						xpos = (rand() % 1300);
						if (xpos > 1550)
							xpos = 1450;
						entities.getElement(i)->setPosition(xpos, ypos[it]);
					}
					else if (ypos.at(it) == 480) {
						xpos = (rand() % 1400) + 300;
						entities.getElement(i)->setPosition(xpos, ypos[it]);
					}
					else if (ypos.at(it) == 740) {
						xpos = (rand() % 1000) + 500;
						entities.getElement(i)->setPosition(xpos, ypos[it]);
					}

				}
				if (entities.getElement(i)->getID() == 4)//Bunny
				{
					std::vector<float> ypos = { 170, 490, 750 };

					int it = (rand() % 3);

					if (ypos.at(it) == 170) {
						xpos = (rand() % 1300);
						entities.getElement(i)->setPosition(xpos, ypos[it]);
						if (xpos > 1550)
							xpos = 1550;
					}
					else if (ypos.at(it) == 490) {
						xpos = (rand() % 1400) + 300;
						entities.getElement(i)->setPosition(xpos, ypos[it]);
					}
					else if (ypos.at(it) == 750) {
						xpos = (rand() % 1000) + 500;
						entities.getElement(i)->setPosition(xpos, ypos[it]);
					}
				}
				if (entities.getElement(i)->getID() == 5)//Inverse
				{
					std::vector<float> ypos = { 740, 482, 162 };

					int it = (rand() % 3);

					if (ypos.at(it) == 162) {
						xpos = (rand() % 1300);
						if (xpos > 1550)
							xpos = 1550;
						entities.getElement(i)->setPosition(xpos, ypos[it]);
					}
					else if (ypos.at(it) == 482) {
						xpos = (rand() % 1400) + 300;
						entities.getElement(i)->setPosition(xpos, ypos[it]);
					}
					else if (ypos.at(it) == 740) {
						xpos = (rand() % 1000) + 500;
						entities.getElement(i)->setPosition(xpos, ypos[it]);
					}
				}
			}
		}



		SecondGameState::SecondGameState(sf::RenderWindow* window, std::stack<State*>* states) :GameState(window, states)
		{
			initFont();
			initTextures();
			initPlayers();
			initList();
			initPositions();
			initPauseMenu();

			initScore(100);
			initLife();


			collisionsP1.add(player, &entities);
			collisionsP2.add(player2, &entities);

			this->map = new Entity::SecondTileMap();

			door.setFillColor(sf::Color::Magenta);
			door.setSize(sf::Vector2f(50, 100));
			door.setPosition(1400, 750);
		}

		SecondGameState::~SecondGameState()
		{

			delete player;
			delete player2;
			delete pauseMenu;

			entities.destroy();

			auto it = this->btns.begin();

			for (it = this->btns.begin(); it != this->btns.end(); ++it)
			{
				delete it->second;
			}
		}
	}
}

