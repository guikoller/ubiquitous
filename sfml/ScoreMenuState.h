#pragma once

#include "GameMenuState.h"


class ScoreMenuState : public State {
private:

    sf::Text title;

    sf::Text scores;

    sf::Texture texture;
    sf::Sprite background;

    Button* btn;

    std::map<std::string, Button*> btns;

    void initButton();
    void initBackground();
    void initTitle();
    void initScore();
public:
    ScoreMenuState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~ScoreMenuState();
    void updateButton();
    void update(const float& dt);
    void renderButton(sf::RenderTarget& target);
    void render(sf::RenderTarget& target);
    
    std::string readFile();
};
