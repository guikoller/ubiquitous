#pragma once

#include <SFML/Graphics.hpp>
#include <stack>

class State {
public:
    std::stack<State*>* states;

    sf::RenderWindow* window;
    bool quit;

    sf::Font fonte;

    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    void initFont();
public:
    State(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~State();

    const bool& getQuit() const;
    virtual void checkQuit();
    virtual void endState();
    virtual void updateMousePosition();

    virtual void updateKeybinds();
    virtual void update();
    virtual void render(sf::RenderTarget& target) = 0;
};

