#pragma once
#include <stack>
#include <SFML/Graphics.hpp>
#include "State.h"



class Game {
private:
    sf::RenderWindow window;
    sf::Event event;//checa eventos da jenela como teclas pressionadas comando de fechamendo, minimizazão

    // MenuPrincipal menu;

    sf::Clock dtClock;
    float dt;

    std::stack <State*> states;


    void initWindow();
    void initStates();
public:
    Game(/* args */);
    ~Game();

    //Functions
    const sf::RenderWindow& getWindow() const;//retorna estado da janela (aberta ou fechada)
    void update();
    void updateDT();
    void updateSFMLevents();
    void updateState();
    void render();
    void executar();
};
