#pragma once

#include "State.h"
#include "CollisionManager.h"
#include "PauseMenu.h"
#include "MainTileMap.h"


class GameState : public State{
private:
	PauseMenu* pauseMenu;
	Player* player;
	Player* player2;
	
	EntityList entities;

	CollisionManager collisionsP1;
	CollisionManager collisionsP2;

	TileMap *map;


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
	void initList();
	void initPositions();
	
	void initPauseMenu();


	void initScore(int placar);
	void initLife();
public:
	GameState(sf::RenderWindow* window, std::stack<State*>* states);
	~GameState();
	

	void save();

	void moveEnemies(const float& dt);
	
	void updateInput(const float& dt);
	void updateKeybinds(const float& dt);
	void updatePlayerInput(const float& dt);
	void updateButtons();
	
	void updateScore();
	void updateLife();
	
	void update(const float& dt);
	void render(sf::RenderTarget& target);
};

