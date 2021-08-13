#pragma once

#include "State.h"
#include "CollisionManager.h"
#include "PauseMenu.h"
#include "Tilemap.h"


class GameState : public State{
private:
	PauseMenu *pauseMenu;
	Player *player;
	
	EntityList entities;

	CollisionManager collisions;

	TileMap map;

	//Functions
	void initTextures();
	
	void initPlayers();
	void initList();
	
	void initPauseMenu();
public:
	GameState(sf::RenderWindow* window, std::stack<State*>* states);
	~GameState();
	
	
	void moveEnemies(const float& dt);
	
	void updateInput(const float& dt);
	void updateKeybinds(const float& dt);
	void updatePlayerInput(const float& dt);
	void updateButtons();
	//void updateCollision();
	
	void update(const float& dt);
	void render(sf::RenderTarget& target);
};

