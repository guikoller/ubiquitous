#pragma once
#include "FirstGameState.h"

class SecondGameState : public GameState {
public:
	SecondGameState(sf::RenderWindow* window, std::stack<State*>* states);
	~SecondGameState();
};