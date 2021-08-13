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
	player = new Player(100,100,textures["PLAYER_SHEET"]);
}


void GameState::initList() {
	entities.add(new Enemy(300, 200, textures["ENEMY_SHEET"]));
	entities.add(new Plant(600, 200, textures["PLANT_SHEET"]));
	entities.add(new Bunny(500, 30, textures["BUNNY_SHEET"]));
	entities.add(new Portal(300, 500, textures["PORTAL_SHEET"]));
	entities.add(new Flame(500, 400, textures["FLAME_SHEET"]));
	entities.add(new Box(600, 300, textures["BOX"]));
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
	initList();
	initPauseMenu();
	collisions.add(player, &entities);
}


GameState::~GameState() {
	delete player;

	delete pauseMenu;
	
	entities.destroy();
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
	//updateCollision();

	if (!paused) {
		updatePlayerInput(dt);
		
		player->update(dt);
		
		entities.update(dt);

		collisions.update(dt);

		map.updateCollision(player, dt);
	}
	if(paused) {
		updateButtons();
		pauseMenu->update(this->mousePosView);
	}	
}

void GameState::render(sf::RenderTarget& target){
	this->map.render(target);
	
	entities.render(target);

	player->render(target);
	
	if (paused) {
		//PAUSE RENDER
		pauseMenu->render(target);

	}
}




