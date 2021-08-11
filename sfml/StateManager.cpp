#include "StateManager.h"

StateManager::StateManager(State* states) {
	this->states.push(states);
}
StateManager::~StateManager() {
	while (!this->states.empty())
	{
		delete states.top();
		states.pop();
	}
}

void StateManager::addState(State* state) {
	if (state != nullptr)
		states.push(state);
}
const bool StateManager::isEmpty()const {
	return states.empty();
}

void StateManager::update(const float& dt) {
	this->states.top()->update(dt);

	if (states.top()->getQuit()) {
		states.top()->endState();
		delete states.top();
		states.pop();
	}
}
void StateManager::render(sf::RenderWindow& target) {
	if (!states.empty())
		states.top()->render(target);
}