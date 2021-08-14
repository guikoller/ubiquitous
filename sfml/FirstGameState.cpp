#include "FirstGameState.h"

FirstGameState::FirstGameState(sf::RenderWindow* window, std::stack<State*>* states) :GameState(window, states)
{
	initFont();
	initTextures();
	initPlayers();
	initList();
	initPositions();
	initPauseMenu();

	initScore(100);
	initLife();


	collisionsP1.add(player, &entities);
	collisionsP2.add(player2, &entities);
	this->map = new MainTileMap();
}

FirstGameState::~FirstGameState()
{

	delete player;
	delete player2;
	delete pauseMenu;

	entities.destroy();

	auto it = this->btns.begin();

	for (it = this->btns.begin(); it != this->btns.end(); ++it)
	{
		delete it->second;
	}
}
