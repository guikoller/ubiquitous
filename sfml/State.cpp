#include "State.h"

State::State(sf::RenderWindow* window, std::stack<State*>* states) {
    this->window = window;
    this->quit = false;
    initFont();
    this->states = states;
}

State::~State()
{
}


void State::initFont() {
    try{
        this->font.loadFromFile("Fonts/font.ttf");
    }
    catch (const std::exception&){
        throw("ERRO FONTE N�O CARREGADA");
    }
}

void State::update() {
    // this->updateEntidade();
    // this->updateColisao();
    this->updateKeybinds();
    this->updateMousePosition();
    //std::cout << this->mousePosWindow.x << ", " << this->mousePosWindow.y << std::endl;
    system("clear");
}

void State::checkQuit() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {
        this->quit = true;
    }
}

const bool& State::getQuit() const {
    return this->quit;
}

void State::updateKeybinds() {
    return this->checkQuit();
}


void State::endState() {
    printf("STATE FINALIZADO!\n");
}

void State::updateMousePosition() {
    this->mousePosScreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}