#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states) :State(window, states) {

}

GameState::~GameState() {

}



void GameState::updateKeybinds(const float& dt) {
	this->checkQuit();
}
void GameState::update(const float& dt)
{
	updateKeybinds(dt);
	this->player.update(dt);
}

void GameState::render(sf::RenderTarget& target){
	player.render(target);
}




