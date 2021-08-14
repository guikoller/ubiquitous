#pragma once

#include "GameState.h"

class FirstGameState : public GameState {
public:
	FirstGameState(sf::RenderWindow* window, std::stack<State*>* states);
	~FirstGameState();
};