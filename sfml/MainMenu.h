#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include "State.h"
#include "Button.h"
#include "GameState.h"


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
