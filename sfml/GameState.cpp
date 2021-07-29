#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states) :State(window, states) {

}

GameState::~GameState() {

}

void GameState::update()
{
}

void GameState::render(sf::RenderTarget& target)
{
}




