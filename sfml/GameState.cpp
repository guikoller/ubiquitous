#include "GameState.h"

void GameState::initTextures() {
	
	try{
		this->textures["xereque"].loadFromFile("Resources/sprites/xereque.png");
	}
	catch (const std::exception&){
		printf("XEREQUE NÃO CARREGADO\n");
	}	
}
void GameState::initPlayers() {
	player = new Player(0,0,textures["xereque"]);
}

void GameState::updateKeybinds(const float& dt) {
	this->checkQuit();
}

void GameState::updateInput(const float& dt) {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		player->move(dt, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		player->move(dt, 1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		player->move(dt, 0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		player->move(dt, 0.f, 1.f);

}


GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states) :State(window, states) {
	initTextures();
	initPlayers();
}

GameState::~GameState() {
	delete player;
}


void GameState::update(const float& dt)
{
	updateKeybinds(dt);
	updateInput(dt);
	this->player->update(dt);
}

void GameState::render(sf::RenderTarget& target){
	player->render(target);
}




