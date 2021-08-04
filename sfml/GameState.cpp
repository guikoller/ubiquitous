#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states) :State(window, states) {

}

GameState::~GameState() {

}

void GameState::update(const float dt)
{
	this->player.update(dt);
}

void GameState::render(sf::RenderTarget* target){
	this->player.render(target);
}




