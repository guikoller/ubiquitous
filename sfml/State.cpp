#include "State.h"
namespace State {
    State::State(sf::RenderWindow* window, std::stack<State*>* states) {
        this->window = window;
        this->quit = false;
        this->paused = false;
        initFont();
        this->states = states;
    }

    State::~State() {
    }


    void State::initFont() {
        try {
            this->font.loadFromFile("Fonts/font.ttf");
        }
        catch (const std::exception&) {
            throw("ERRO FONTE NÃO CARREGADA");
        }
    }

    void State::update(const float& dt) {
        this->updateKeybinds();
        this->updateMousePosition();
    }

    void State::checkQuit() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
        {
            this->quit = true;
        }
    }

    void State::pauseState()
    {
        this->paused = true;
    }

    void State::unpauseState()
    {
        this->paused = false;
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
}