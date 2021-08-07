#pragma once

#include "GameState.h"
#include "NewGameMenuState.h"


class GameMenuState : public State {
private:
    sf::Texture texture;
    sf::Sprite background;

    Button* btn;

    std::map<std::string, Button*> btns;

    void initButton();
    void initBackground();
public:
    GameMenuState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~GameMenuState();
    void updateButton();
    void update(const float& dt);
    void renderButton(sf::RenderTarget& target);
    void render(sf::RenderTarget& target);
};
