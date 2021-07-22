#pragma once

#include <stdlib.h>
#include "State.h"
#include "Button.h"

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
    void update();
    void renderButton(sf::RenderTarget& target);
    virtual void render(sf::RenderTarget& target);
};
