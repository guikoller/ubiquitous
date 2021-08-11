#include "GameState.h"

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
		printf("PLAYER_SHEET COULD NOT LOAD\n");
	}	
}


void GameState::initPlayers() {
	player = new Player(0,0,textures["PLAYER_SHEET"]);
}


void GameState::initEnemies() {
	enemy = new Enemy(300, 200, textures["ENEMY_SHEET"]);
	plant = new Plant(600, 200, textures["PLANT_SHEET"]);
	bunny = new Bunny(500, 30, textures["BUNNY_SHEET"]);
}

void GameState::initObstacles() {
	portal = new Portal(300, 500, textures["PORTAL_SHEET"]);
	flame = new Flame(500, 400, textures["FLAME_SHEET"]);
	box = new Box(600, 300, textures["BOX"]);
}

void GameState::initPauseMenu() {
	pauseMenu = new PauseMenu(*window, font);
	pauseMenu->addButton("QUIT", 800.f, "quit");
}

void GameState::moveEnemies(const float& dt) {
	bunny->move(dt, 10, 0);
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
		bunny->move(dt, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		bunny->move(dt, 1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		bunny->move(dt, 0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		bunny->move(dt, 0.f, 1.f);
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


GameState::~GameState() {
	delete player;
	
	delete bunny;
	delete plant;
	delete enemy;
	
	delete portal;
	delete flame;
	delete box;
	
	delete pauseMenu;
}


void GameState::updateButtons() {
	if (pauseMenu->isButtonPressed("QUIT"))
	{
		endState();
		printf("clicou\n");
	}
}




void GameState::update(const float& dt)
{
	updateKeybinds(dt);
	updateInput(dt);

	if (!paused) {
		updatePlayerInput(dt);
		//moveEnemies(dt);
		this->player->update(dt);
		this->enemy->update(dt);
		this->plant->update(dt);
		this->bunny->update(dt);
		this->portal->update(dt);
		this->flame->update(dt);
		this->box->update(dt);
	}
	if(paused) {
		updateButtons();
		pauseMenu->update(this->mousePosView);
	}	
}

void GameState::render(sf::RenderTarget& target){
	
	enemy->render(target);
	bunny->render(target);
	plant->render(target);
	flame->render(target);
	portal->render(target);
	box->render(target);

	player->render(target);
	
	if (paused) {
		//PAUSE RENDER
		pauseMenu->render(target);

	}
}




