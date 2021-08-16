#include "FirstGameState.h"
namespace State {
	namespace GameState {
		FirstGameState::FirstGameState(sf::RenderWindow* window, std::stack<State*>* states) :GameState(window, states)
		{
			initFont();
			initTextures();
			initPlayers();
			player->hitboxComponent->setPosition(100,700);
			initList();
			initPositions();
			initPauseMenu();

			initScore(100);
			initLife();


			collisionsP1.add(player, &entities);
			collisionsP2.add(player2, &entities);
			this->map = new Entity::MainTileMap();

			projectiles = new EntityList();
			
			door.setFillColor(sf::Color::Magenta);
			door.setSize(sf::Vector2f(50, 100));
			door.setPosition(1400, 150);
		}

		FirstGameState::~FirstGameState()
		{

			delete player;
			delete player2;
			delete pauseMenu;
			delete projectiles;

			entities.destroy();
			entities.destroy();

			auto it = this->btns.begin();

			for (it = this->btns.begin(); it != this->btns.end(); ++it)
			{
				delete it->second;
			}
		}
	}
}