#pragma once
#include "State.h"


class StateManager{
private:
	std::stack <State*> states;	
public:
	StateManager(State* states);
	~StateManager();

	void addState(State* state);
	const bool isEmpty()const;

	void update(const float& dt);
	void render(sf::RenderWindow& target);

};

