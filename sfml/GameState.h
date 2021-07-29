#pragma once
#include "State.h"
class GameState : public State{
private:
	sf::RectangleShape player;
public:
	GameState(sf::RenderWindow* window, std::stack<State*>* states);
	~GameState();
	void update();
	void render(sf::RenderTarget& target);
};

