#pragma once


#include <cstdlib>
#include <ctime>

#include "State.h"
#include "CollisionManager.h"
#include "PauseMenu.h"
#include "MainTileMap.h"

namespace State {
	namespace GameState {
		class GameState : public State {
		public:
			PauseMenu* pauseMenu;
			Entity::Player::Player* player;
			Entity::Player::Player* player2;
			sf::RectangleShape door;

			EntityList entities;
			EntityList* projectiles;

			CollisionManager collisionsP1;
			CollisionManager collisionsP2;

			Entity::TileMap* map;
			sf::Clock clock;

			int score;
			bool write;
			sf::Text ScoreText;
			sf::Text LifeText;

			std::map<std::string, Button*> btns;
			bool paused;
			bool secondPlayer;

			//Functions
			void initTextures();

			void initPlayers();
			virtual void initList();
			virtual void initPositions();

			void initPauseMenu();


			void initScore(int placar);
			void initLife();
		public:
			GameState(sf::RenderWindow* window, std::stack<State*>* states);
			virtual ~GameState();


			void save();
			void load();

			//void moveEnemies(const float& dt);

			void updateInput(const float& dt);
			void updateKeybinds(const float& dt);
			void updatePlayerInput(const float& dt);
			void updateButtons();
			void createProjectiles();
			void updateProjectiles(const float& dt);

			void updateScore();
			void updateLife();

			void update(const float& dt);
			void render(sf::RenderTarget& target);
		};
	}
}


