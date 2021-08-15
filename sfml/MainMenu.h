#pragma once

#include "ScoreMenuState.h"

namespace State {
    namespace Menu {
        class MainMenu : public State {
        private:

            sf::Text title;

            sf::Texture texture;
            sf::Sprite background;

            Button* btn;

            std::map<std::string, Button*> btns;

            void initButton();
            void initBackground();
            void initTitle();
        public:
            MainMenu(sf::RenderWindow* window, std::stack<State*>* states);
            virtual ~MainMenu();
            void updateButton();
            void update(const float& dt);
            void renderButton(sf::RenderTarget& target);
            void render(sf::RenderTarget& target);
        };
    }
}