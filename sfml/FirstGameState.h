#pragma once
#include "GameState.h"

namespace State {
	namespace GameState {
		class FirstGameState : public GameState {
		public:
			FirstGameState(sf::RenderWindow* window, std::stack<State*>* states);
			~FirstGameState();
		};
	}
}