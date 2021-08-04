#pragma once
#include "State.h"
#include "Entity.h"
class GameState : public State{
private:
	Entity player;
public:
	GameState(sf::RenderWindow* window, std::stack<State*>* states);
	~GameState();
	void update(const float dt);
	void render(sf::RenderTarget* target);
};

