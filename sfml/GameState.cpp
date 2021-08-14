#include "GameState.h"

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
	
	try{
		this->textures["PLAYER_SHEET"].loadFromFile("Resources/sprites/pinkman.png");
		this->textures["ENEMY_SHEET"].loadFromFile("Resources/sprites/manpink.png");
		this->textures["PORTAL_SHEET"].loadFromFile("Resources/sprites/portal.png");
		this->textures["BUNNY_SHEET"].loadFromFile("Resources/sprites/bunny.png");
		this->textures["PLANT_SHEET"].loadFromFile("Resources/sprites/plant.png");
		this->textures["FLAME_SHEET"].loadFromFile("Resources/sprites/flame.png");
		this->textures["BOX"].loadFromFile("Resources/sprites/box.png");
	}
	catch (const std::exception&){
		throw("PLAYER_SHEET COULD NOT LOAD\n");
	}	
}

void GameState::initPlayers() {
	player = new Player(100,100,textures["PLAYER_SHEET"]);
	player2 = new Player(2000, 2000, textures["PLAYER_SHEET"]);
}

void GameState::initList() {
	entities.add(new Enemy(900, 800, textures["ENEMY_SHEET"]));
	entities.add(new Enemy(900, 800, textures["ENEMY_SHEET"]));
	entities.add(new Enemy(900, 800, textures["ENEMY_SHEET"]));
	
	entities.add(new Plant(600, 300, textures["PLANT_SHEET"]));
	entities.add(new Plant(600, 300, textures["PLANT_SHEET"]));
	entities.add(new Plant(600, 300, textures["PLANT_SHEET"]));
	
	entities.add(new Bunny(900, 500, textures["BUNNY_SHEET"]));
	entities.add(new Bunny(900, 500, textures["BUNNY_SHEET"]));
	entities.add(new Bunny(900, 500, textures["BUNNY_SHEET"]));
	
	entities.add(new Portal(1000, 130, textures["PORTAL_SHEET"]));
	entities.add(new Portal(1450, 700, textures["PORTAL_SHEET"]));

	
	entities.add(new Flame(0, 0, textures["FLAME_SHEET"]));
	entities.add(new Flame(0, 0, textures["FLAME_SHEET"]));
	entities.add(new Flame(0, 0, textures["FLAME_SHEET"]));
	entities.add(new Flame(0, 0, textures["FLAME_SHEET"]));

	
	entities.add(new Box(200, 784, textures["BOX"]));
	entities.add(new Box(400, 784, textures["BOX"]));
	entities.add(new Box(840, 530, textures["BOX"]));
	entities.add(new Box(500, 784, textures["BOX"]));
	entities.add(new Box(456, 784, textures["BOX"]));
	entities.add(new Box(840, 210, textures["BOX"]));

}


void GameState::initPositions() {

	std::srand((unsigned)std::time(0));

	float xpos;

	for (int i = 0; i < entities.length() ; i++)
	{
		if (entities.getElement(i)->getID() == 1)//Box
		{
			std::vector<float> ypos = { 210, 530, 784 };

			int it = (rand() % 3);

			if (ypos.at(it) == 210) {
				xpos = (rand() % 1300) + 200;
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

			int it  = (rand() % 3);

			if (ypos.at(it) == 160){
				xpos = (rand() % 1300) + 200;
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
		if (entities.getElement(i)->getID() == 3)//POrtal
		{

		}
		if (entities.getElement(i)->getID() == 4)//Bunny
		{

		}
		if (entities.getElement(i)->getID() == 5)//Inverse
		{

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
	this->map = new MainTileMap();
}

GameState::~GameState() {
	delete player;
	
	entities.destroy();

	auto it = this->btns.begin();

	for (it = this->btns.begin(); it != this->btns.end(); ++it)
	{
		delete it->second;
	}

}

void GameState::updateKeybinds(const float& dt) {
	this->checkQuit();
}

void GameState::updateInput(const float& dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		paused = true;
		this->write = true;
	}
}

void GameState::updatePlayerInput(const float& dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		player->move(dt, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		player->move(dt, 1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		player->move(dt, 0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		player->move(dt, 0.f, 1.f);


	if (secondPlayer) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			player2->move(dt, -1.f, 0.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			player2->move(dt, 1.f, 0.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			player2->move(dt, 0.f, -1.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			player2->move(dt, 0.f, 1.f);
	}
}

void GameState::updateButtons() {
	if (pauseMenu->isButtonPressed("QUIT"))
	{
		quit = true;
	}else if(pauseMenu->isButtonPressed("PLAY"))
	{
		paused = false;
	}
	else if (pauseMenu->isButtonPressed("SAVE"))
	{
		save();
	}
	else if (pauseMenu->isButtonPressed("LOAD"))
	{
		paused = false;
	}
	else if (pauseMenu->isButtonPressed("ADD"))
	{
		secondPlayer = true;
		player2->setPosition(100, 700);
	}
}

void GameState::updateScore() {
	this->ScoreText.setString(std::to_string(this->score));
}

void GameState::updateLife() {
	int vida = this->player->getID();
	this->LifeText.setString(std::to_string(vida));
	if (vida <= 0) {
		//this->quit = true;
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
		collisionsP1.update(dt);
		map->updateCollision(player, dt);
	
		updateScore();
		updateLife();
	}
	if(paused) {
		updateButtons();
		pauseMenu->update(mousePosView);
	}	
}

void GameState::render(sf::RenderTarget& target){
	this->map->render(target);
	
	entities.render(target);

	player->render(target);
	if (secondPlayer)
		player2->render(target);
	
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
}