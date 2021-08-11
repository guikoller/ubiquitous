#pragma once
#include "State.h"

class StateManagement{
private:
	std::stack <State*> states;
	
	
	void pushState(sf::RenderWindow &target, State *states) {
		//this->states.push(new MainMenu(&window, &this->states));
	}
public:
	StateManagement() {

	}
	~StateManagement() {
		while (!this->states.empty())
		{
			delete states.top();
			states.pop();
		}
	}

	void update(const float& dt) {
		this->states.top()->update(dt);

		if (states.top()->getQuit()) {
			states.top()->endState();
			delete states.top();
			states.pop();
		}
	}
	void render(sf::RenderWindow& target) {
		if (!states.empty())
			states.top()->render(target);
	}

};

