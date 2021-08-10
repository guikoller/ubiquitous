#include "GameState.h"

void GameState::initTextures() {
	
	try{
		this->textures["PLAYER_SHEET"].loadFromFile("Resources/sprites/pinkman.png");
	}
	catch (const std::exception&){
		printf("PLAYER_SHEET COULD NOT LOAD\n");
	}	
}
void GameState::initPlayers() {
	player = new Player(0,0,textures["PLAYER_SHEET"]);
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
		if (!paused)
			pauseState();
		else		
			unpauseState();

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
	initPauseMenu();
}

void GameState::updateButtons() {
	if (pauseMenu->isButtonPressed("QUIT"))
	{
		endState();
	}
}

GameState::~GameState() {
	delete player;
	delete pauseMenu;
}


void GameState::update(const float& dt)
{
	updateKeybinds(dt);
	updateInput(dt);
	
	if (!paused) {
		
		updatePlayerInput(dt);
		this->player->update(dt);
	}
	else {
		pauseMenu->update(this->mousePosView);
		updateButtons();
	}

	
}

void GameState::render(sf::RenderTarget& target){
	player->render(target);
	if (paused) {
		//PAUSE RENDER
		pauseMenu->render(target);

	}
}




