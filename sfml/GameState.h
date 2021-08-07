#pragma once
#include "State.h"
#include "Player.h"
class GameState : public State{
private:
	Player *player;

	//Functions
	void initTextures();
	void initPlayers();
public:
	GameState(sf::RenderWindow* window, std::stack<State*>* states);
	~GameState();

	void updateKeybinds(const float& dt);
	void updateInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget& target);
};

