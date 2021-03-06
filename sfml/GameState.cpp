#include "GameState.h"
namespace State {
	namespace GameState {
		void GameState::initScore(int score) {
			bool write = true;
			this->score = score;
			this->ScoreText.setFont(this->font);
			this->ScoreText.setFillColor(sf::Color::White);
			this->ScoreText.setCharacterSize(70);
			this->ScoreText.setPosition(sf::Vector2f(1300.f, 30.f));
		}

		void GameState::initLife() {
			this->LifeText.setFont(this->font);
			this->LifeText.setFillColor(sf::Color::White);
			this->LifeText.setCharacterSize(70);
			this->LifeText.setPosition(sf::Vector2f(200.f, 30.f));
		}

		void GameState::initTextures() {

			try {
				this->textures["PLAYER_SHEET"].loadFromFile("Resources/sprites/pinkman.png");
				this->textures["ENEMY_SHEET"].loadFromFile("Resources/sprites/manpink.png");
				this->textures["PORTAL_SHEET"].loadFromFile("Resources/sprites/portal.png");
				this->textures["BUNNY_SHEET"].loadFromFile("Resources/sprites/bunny.png");
				this->textures["PLANT_SHEET"].loadFromFile("Resources/sprites/plant.png");
				this->textures["FLAME_SHEET"].loadFromFile("Resources/sprites/flame.png");
				this->textures["BOX"].loadFromFile("Resources/sprites/box.png");
				this->textures["BULLET"].loadFromFile("Resources/sprites/Bullet.png");
			}
			catch (const std::exception&) {
				throw("PLAYER_SHEET COULD NOT LOAD\n");
			}
		}

		void GameState::initPlayers() {
			player = new Entity::Player::Player(784, 100, textures["PLAYER_SHEET"]);
			player2 = new Entity::Player::Player(2000, 2000, textures["PLAYER_SHEET"]);
		}

		void GameState::initList() {
			for (int i = 0; i < 3; i++)
				entities.add(new Entity::Enemy::Enemy(0, 0, textures["ENEMY_SHEET"]));


			entities.add(new Entity::Enemy::Plant(123, 493, textures["PLANT_SHEET"]));

			for (int i = 0; i < 3; i++)
				entities.add(new Entity::Enemy::Bunny(0, 0, textures["BUNNY_SHEET"]));


			entities.add(new Entity::Obstacle::Portal(1400, 700, textures["PORTAL_SHEET"]));

			for (int i = 0; i < 3; i++)
				entities.add(new Entity::Obstacle::Flame(0, 0, textures["FLAME_SHEET"]));

			for (int i = 0; i < 4; i++)
				entities.add(new Entity::Obstacle::Box(0, 0, textures["BOX"]));
		}

		void GameState::initPositions() {

			std::srand((unsigned)std::time(0));

			float xpos;

			for (int i = 0; i < entities.length(); i++)
			{
				if (entities.getElement(i)->getID() == 1)//Box
				{
					std::vector<float> ypos = { 210, 530, 784 };

					int it = (rand() % 3);

					if (ypos.at(it) == 210) {
						xpos = (rand() % 1500) + 400;
						if (xpos > 1550)
							xpos = 1550;
						entities.getElement(i)->setPosition(xpos, ypos[it]);
					}
					else if (ypos.at(it) == 530) {
						xpos = (rand() % 1000) + 64;
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
						xpos = (rand() % 1300) + 400;
						if (xpos > 1550)
							xpos = 1550;
						entities.getElement(i)->setPosition(xpos, ypos[it]);
					}
					else if (ypos.at(it) == 480) {
						xpos = (rand() % 1000) + 64;
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
						xpos = (rand() % 1500) + 300;
						entities.getElement(i)->setPosition(xpos, ypos[it]);
						if (xpos > 1550)
							xpos = 1550;
					}
					else if (ypos.at(it) == 490) {
						xpos = (rand() % 1000) + 64;
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
						xpos = (rand() % 1300) + 400;
						if (xpos > 1550)
							xpos = 1550;
						entities.getElement(i)->setPosition(xpos, ypos[it]);
					}
					else if (ypos.at(it) == 482) {
						xpos = (rand() % 1000) + 64;
						entities.getElement(i)->setPosition(xpos, ypos[it]);
					}
					else if (ypos.at(it) == 740) {
						xpos = (rand() % 1000) + 500;
						entities.getElement(i)->setPosition(xpos, ypos[it]);
					}
				}
				if (entities.getElement(i)->getID() == 6)//Plant
				{

				}
			}
		}

		void GameState::initPauseMenu() {
			pauseMenu = new PauseMenu(*window, font);
			pauseMenu->addButton("PLAY", 400.f, "play");
			pauseMenu->addButton("SAVE", 500.f, "save");
			pauseMenu->addButton("LOAD", 600.f, "load");
			pauseMenu->addButton("ADD", 700.f, "add player");
			pauseMenu->addButton("QUIT", 800.f, "quit");
		}

		GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states) :State(window, states)
		{
			/*
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

			this->map = new Entity::MainTileMap();*/
		}

		GameState::~GameState() {
			/*delete player;
			delete player2;
			delete pauseMenu;

			entities.destroy();

			auto it = this->btns.begin();

			for (it = this->btns.begin(); it != this->btns.end(); ++it)
			{
				delete it->second;
			}*/

		}

		void GameState::updateKeybinds(const float& dt) {
			this->checkQuit();
			if (player->hitboxComponent->intersects(door.getGlobalBounds()) || player2->hitboxComponent->intersects(door.getGlobalBounds()))
			{
				quit = true;
			}
		}

		void GameState::updateInput(const float& dt) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				paused = true;
				this->write = true;
			}
		}

		void GameState::updatePlayerInput(const float& dt) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				player->move(dt, -2.f, 0.f);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				player->move(dt, 2.f, 0.f);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				player->move(dt, 0.f, -2.f);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				player->move(dt, 0.f, 2.f);


			if (secondPlayer) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					player2->move(dt, -2.f, 0.f);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
					player2->move(dt, 2.f, 0.f);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
					player2->move(dt, 0.f, -2.f);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
					player2->move(dt, 0.f, 2.f);
			}
		}

		void GameState::updateButtons() {
			if (pauseMenu->isButtonPressed("QUIT"))
			{
				quit = true;
			}
			else if (pauseMenu->isButtonPressed("PLAY"))
			{
				paused = false;
			}
			else if (pauseMenu->isButtonPressed("SAVE"))
			{
				save();
			}
			else if (pauseMenu->isButtonPressed("LOAD"))
			{
				load();
			}
			else if (pauseMenu->isButtonPressed("ADD"))
			{
				secondPlayer = true;
				player2->setPosition(100, 700);
			}
		}

		void GameState::createProjectiles()
		{


			if (clock.getElapsedTime().asSeconds() >= 0.8 && projectiles->length()<20)
			{
				projectiles->add(new Entity::Obstacle::Bullet(80, 488, textures["BULLET"]));
				printf("projectile created\n");
			}
			if (clock.getElapsedTime().asSeconds() >= 0.8)
			{
				clock.restart();
			}
		}

		void GameState::updateScore() {
			this->ScoreText.setString(std::to_string(this->player->getScore()));
		}

		void GameState::updateLife() {
			int vida = this->player->getLife();
			this->LifeText.setString(std::to_string(vida));
			if (vida <= 0) {
				this->quit = true;
			}
		}

		void GameState::update(const float& dt)
		{
			updateKeybinds(dt);
			updateInput(dt);
			updateMousePosition();
			updatePlayerInput(dt);
			//updateCollision();

			if (!paused) {

				player->update(dt);
				if (secondPlayer) {
					player2->update(dt);
					map->updateCollision(player2, dt);
					collisionsP2.update(dt);
				}

				entities.update(dt);
				//moveEnemies(dt);
				collisionsP1.update(dt);

				map->updateCollision(player, dt);

				updateScore();
				updateLife();
				if (projectiles) {
					createProjectiles();
					projectiles->update(dt);
					for (int i = 0; i < projectiles->length(); i++)
					{
						if (projectiles->getElement(i)->hitboxComponent->intersects(player->getGlobalBounds()))
						{
							projectiles->getElement(i)->setPosition(10000, 10000);
							player->addLife(-10);
						}
					}

				}

			}
			if (paused) {
				updateButtons();
				pauseMenu->update(mousePosView);
			}
		}

		void GameState::render(sf::RenderTarget& target) {
			this->map->render(target);

			entities.render(target);

			target.draw(door);

			player->render(target);
			if (secondPlayer)
				player2->render(target);

			if (projectiles)
				projectiles->render(target);

			target.draw(this->ScoreText);

			target.draw(this->LifeText);

			if (paused) {
				//PAUSE RENDER
				pauseMenu->render(target);
			}
		}

		void GameState::save() {
			if (write) {
				file.open("Saves/score.txt", std::ios::app);
				file << score << "\n";
				file.close();
				this->write = false;
			}
			file.open("Saves/save.txt", std::ofstream::out | std::ofstream::trunc);
			file.close();
			player->save();
			for (int i = 0; i < entities.length(); i++)
			{
				entities.getElement(i)->save();
			}
		}
		void GameState::load() {
			std::vector<float> pos;
			float input;
			std::ifstream file("Saves/save.txt");

			while (file >> input)
			{
				pos.push_back(input);
			}

			player->setPosition(pos.at(0), pos.at(1));
		}
	}
}
