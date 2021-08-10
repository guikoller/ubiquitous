#pragma once

#include "State.h"
#include "Player.h"
#include "Enemy.h"
#include "Portal.h"
#include "Bunny.h"
#include "PauseMenu.h"
#include "Flame.h"

class GameState : public State{
private:
	PauseMenu *pauseMenu;
	Player *player;
	Enemy* enemy;
	Bunny* bunny;
	Portal* portal;
	Flame* flame;



	//Functions
	void initTextures();
	
	void initPlayers();
	void initEnemies();
	void initObstacles();
	
	void initPauseMenu();
public:
	GameState(sf::RenderWindow* window, std::stack<State*>* states);
	~GameState();
	
	
	void moveEnemies(const float& dt);
	
	void updateInput(const float& dt);
	void updateKeybinds(const float& dt);
	void updatePlayerInput(const float& dt);
	void updateButtons();
	
	void update(const float& dt);
	void render(sf::RenderTarget& target);
};

