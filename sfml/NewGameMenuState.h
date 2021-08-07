#pragma once

#include "GameMenuState.h"


class NewGameMenuState : public State {
private:
    sf::Texture texture;
    sf::Sprite background;

    Button* btn;

    std::map<std::string, Button*> btns;

    void initButton();
    void initBackground();
public:
    NewGameMenuState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~NewGameMenuState();
    void updateButton();
    void update(const float& dt);
    void renderButton(sf::RenderTarget& target);
    void render(sf::RenderTarget& target);
};
