#pragma once
#include "FirstGameState.h"

#include "SecondTileMap.h"
namespace State {
	namespace GameState {
		class SecondGameState : public GameState {
		private:
			void initList();
			void initPositions();
		public:
			SecondGameState(sf::RenderWindow* window, std::stack<State*>* states);
			~SecondGameState();
		};
	}
}
