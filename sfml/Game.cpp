#include "Game.h"

void Game::initWindow() {
    std::ifstream ifs("Resources/Config/window.ini");
    
    std::string title = "None";
    sf::VideoMode window_bounds(1600, 900);
    unsigned framerate_limit = 120;
    bool vertical_sync_enabled = false;
    
    if (ifs.is_open()) {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
    }
    
    ifs.close();

    this->window.create(window_bounds, title);
    sf::View view(sf::FloatRect(0, 0, 1600, 900));
    this->window.setView(view);
    this->window.setFramerateLimit(framerate_limit);
    this->window.setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::initStates() {
    this->states.push(new MainMenu(&window, &this->states));
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
            this->window.close();// checa se uma tecla foi precionada e se foi, se é q para sair do Game                   
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
    //renderização do Game vai aqui

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