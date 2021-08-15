#pragma once
#include "FirstGameState.h"

#include "SecondTileMap.h"
namespace State {
	namespace GameState {
		class SecondGameState : public GameState {
		public:
			SecondGameState(sf::RenderWindow* window, std::stack<State*>* states);
			~SecondGameState();
		};
	}
}
