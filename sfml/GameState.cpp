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
/*
void GameState::updateCollision() {

	sf::FloatRect playerBounds = player->hitboxComponent->getGlobalBounds();
	sf::FloatRect flameBounds = this->flame->hitboxComponent->getGlobalBounds();

	if (player->intersects(flame->getGlobalBounds()))
	{

		//baixo
		if (playerBounds.top < flameBounds.top
			&& playerBounds.top + playerBounds.height < flameBounds.top + flameBounds.height
			&& playerBounds.left < flameBounds.left + flameBounds.width
			&& playerBounds.left + playerBounds.width > flameBounds.left
			)
		{
			
			this->player->movementComponent->stopVelocityY();
			this->player->hitboxComponent->setPosition(playerBounds.left, flameBounds.top -  playerBounds.height);
			printf("colisão chão\n");
		}
		// cima
		else if (playerBounds.top > flameBounds.top
			&& playerBounds.top + playerBounds.height > flameBounds.top + flameBounds.height
			&& playerBounds.left < flameBounds.left + flameBounds.width
			&& playerBounds.left + playerBounds.width > flameBounds.left
			)
		{
			this->player->movementComponent->stopVelocityX();
			this->player->hitboxComponent->setPosition(flameBounds.left + flameBounds.width, playerBounds.top);
			
			printf("colisão topo\n");
		}
		
		//direita
		
		if (playerBounds.left < flameBounds.left
			&& playerBounds.left + playerBounds.width < flameBounds.left + flameBounds.width
			&& playerBounds.top < flameBounds.top + flameBounds.height
			&& playerBounds.top + playerBounds.height > flameBounds.top
			)
		{
			this->player->movementComponent->stopVelocityX();
			this->player->hitboxComponent->setPosition(flameBounds.left - playerBounds.width, playerBounds.top);
				
			printf("colisão direita\n");

		}
		//esquerda
		else if (playerBounds.left > flameBounds.left
			&& playerBounds.left + playerBounds.width > flameBounds.left + flameBounds.width
			&& playerBounds.top < flameBounds.top + flameBounds.height
			&& playerBounds.top + playerBounds.height > flameBounds.top 
			)
		{
			this->player->movementComponent->stopVelocityX();
			this->player->hitboxComponent->setPosition(flameBounds.left + playerBounds.width, playerBounds.top);
			printf("colisão esquerda\n");
		}
	}
}
*/



void GameState::update(const float& dt)
{
	updateKeybinds(dt);
	updateInput(dt);
	//updateCollision();

	if (!paused) {
		updatePlayerInput(dt);
		player->update(dt);
		for (int i = 0; i < entities.length(); i++)
		{
			entities.getElement(i)->update(dt);
			printf("aaa");
		}
	}
	if(paused) {
		updateButtons();
		pauseMenu->update(this->mousePosView);
	}	
}

void GameState::render(sf::RenderTarget& target){
	
	for (int i = 0; i < entities.length(); i++)
	{
		entities.getElement(i)->render(target);
	}

	player->render(target);
	
	if (paused) {
		//PAUSE RENDER
		pauseMenu->render(target);

	}
}




