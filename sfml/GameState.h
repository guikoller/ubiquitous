#pragma once

#include "State.h"
#include "Player.h"
#include "PauseMenu.h"

class GameState : public State{
private:
	PauseMenu *pauseMenu;
	Player *player;

	//Functions
	void initTextures();
	void initPlayers();
	void initPauseMenu();
public:
	GameState(sf::RenderWindow* window, std::stack<State*>* states);
	~GameState();

	void updateInput(const float& dt);
	void updateKeybinds(const float& dt);
	void updatePlayerInput(const float& dt);
	void updateButtons();
	void update(const float& dt);
	void render(sf::RenderTarget& target);
};

