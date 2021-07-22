#include "Game.h"

void Game::initWindow() {

    this->window.create(sf::VideoMode(1600, 1010), "Jogasso");
    sf::View view(sf::FloatRect(0, 0, 1600, 1010));
    this->window.setView(view);
    this->window.setFramerateLimit(144);
    this->window.setVerticalSyncEnabled(true);
}

void Game::initStates() {
    this->states.push(new MenuPrincipal(&window, &this->states));
}

Game::Game() {
    this->initWindow();
    this->initStates();
}
Game::~Game() {
    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }

}


//UPDATES////////////////////////////////////////////
void Game::updateDT() {
    this->dt = this->dtClock.restart().asSeconds();
}
void Game::updateSFMLevents() {
    //pega todos o eventos da janela
    while (this->window.pollEvent(this->event)) {
        if (this->event.type == sf::Event::Closed)//se a janela for fechada
            this->window.close();
        else if (this->event.type == sf::Event::KeyPressed && this->event.key.code == sf::Keyboard::Q)
            this->window.close();// checa se uma tecla foi precionada e se foi, se � q para sair do Game                   
    }
}
void Game::updateState() {
    if (!this->states.empty()) {
        this->states.top()->update();

        if (this->states.top()->getQuit()) {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    else {
        this->window.close();
    }

}
void Game::update() {
    this->updateSFMLevents();
    this->updateDT();
    this->updateState();
}

//RENDER/////////////////////////////////////////////

const sf::RenderWindow& Game::getWindow() const {//retorna estado da janela aberta ou fechada
    return this->window;
}

void Game::render() {
    this->window.clear();
    //renderiza��o do Game vai aqui

    if (!this->states.empty())
        this->states.top()->render(this->window);

    //
    this->window.display();
}

/////////////////////////////////////////////////////

void Game::run() {
    //menu.desenhar(&window);
    while (this->getWindow().isOpen())
    {
        this->update();
        this->render();
    }
}