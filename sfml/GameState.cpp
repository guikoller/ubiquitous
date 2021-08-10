#include "GameState.h"

void GameState::initTextures() {
	
	try{
		this->textures["PLAYER_SHEET"].loadFromFile("Resources/sprites/pinkman.png");
		//this->textures["ENEMY_SHEET"].loadFromFile("Resources/sprites/pinkman.png");
		this->textures["PORTAL_SHEET"].loadFromFile("Resources/sprites/portal.png");
	}
	catch (const std::exception&){
		printf("PLAYER_SHEET COULD NOT LOAD\n");
	}	
}


void GameState::initPlayers() {
	player = new Player(0,0,textures["PLAYER_SHEET"]);
}


void GameState::initEnemies() {
	enemy = new Enemy(0, 0, textures["PLAYER_SHEET"]);
	enemy->setPosition(300, 200);
}

void GameState::initObstacles() {
	portal = new Portal(0, 0, textures["PORTAL_SHEET"]);
	portal->setPosition(300, 500);
}

void GameState::initPauseMenu() {
	pauseMenu = new PauseMenu(*window, font);
	pauseMenu->addButton("QUIT", 800.f, "quit");
}

void GameState::updateKeybinds(const float& dt) {
	this->checkQuit();
}

void GameState::updateInput(const float& dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
		if (!paused) {
			paused = true;
		}		
		else{
			paused = false;
		}
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
}


GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states) :State(window, states)
{
	initFont();
	initTextures();
	initPlayers();
	initEnemies();
	initObstacles();
	initPauseMenu();
}

void GameState::updateButtons() {
	if (pauseMenu->isButtonPressed("QUIT"))
	{
		endState();
		printf("clicou\n");
	}
}

GameState::~GameState() {
	delete player;
	delete enemy;
	delete portal;
	delete pauseMenu;
}


void GameState::update(const float& dt)
{
	updateKeybinds(dt);
	updateInput(dt);

	if (!paused) {
		updatePlayerInput(dt);
		this->player->update(dt);
		this->enemy->update(dt);
		this->portal->update(dt);
	}
	if(paused) {
		updateButtons();
		pauseMenu->update(this->mousePosView);
	}	
}

void GameState::render(sf::RenderTarget& target){
	player->render(target);
	enemy->render(target);
	portal->render(target);
	
	if (paused) {
		//PAUSE RENDER
		pauseMenu->render(target);

	}
}




