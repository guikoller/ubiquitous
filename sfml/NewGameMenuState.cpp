#include "NewGameMenuState.h"

void NewGameMenuState::initButton() {

    this->btns["NAME"] = new Button(500, 250, 220, 80, "...", &this->font,
        sf::Color(0, 0, 0, 230),
        sf::Color(10, 10, 10, 200),
        sf::Color(20, 20, 20, 150));

    this->btns["QPLAYERS"] = new Button(500, 350, 220, 80, "1|2", &this->font,
        sf::Color(0, 0, 0, 230),
        sf::Color(10, 10, 10, 200),
        sf::Color(20, 20, 20, 150));

    this->btns["PLAY"] = new Button(500, 450, 220, 80, "play", &this->font,
        sf::Color(0, 0, 0, 230),
        sf::Color(10, 10, 10, 200),
        sf::Color(20, 20, 20, 150));

    this->btns["QUIT_"] = new Button(500, 550, 220, 80, "<-", &this->font,
        sf::Color(0, 0, 0, 230),
        sf::Color(10, 10, 10, 200),
        sf::Color(20, 20, 20, 150));

}

void NewGameMenuState::initBackground() {
    if (!this->texture.loadFromFile("Resources/Images/bg.png"))
        printf("BACKGROUND N�O CARREGADO\n");

    this->background.setTexture(this->texture);
    this->background.setScale(1.8f, 1.5f);

}

NewGameMenuState::NewGameMenuState(sf::RenderWindow* window, std::stack<State*>* states) :State(window, states) {
    initBackground();
    initButton();
}

NewGameMenuState::~NewGameMenuState()
{
    auto it = this->btns.begin();

    for (it = this->btns.begin(); it != this->btns.end(); ++it)
    {
        delete it->second;
    }


}

void NewGameMenuState::updateButton() {
    for (auto& it : this->btns)
    {
        it.second->update(this->mousePosView);
    }

    // SAIR DO JOGO
    if (this->btns["QUIT_"]->isPressed())
    {
        this->quit = true;
    }
    else if (this->btns["PLAY"]->isPressed())
    {
        // PUSH NOVO STATE
        this->states->push(new GameState(this->window, this->states));

    }
    /*else if (this->btns["LOAD"]->isPressed())
    {
        //this->states->push(new Pontuacao(this->window, this->states));
        printf("Button  placar precionado\n");
    }*/


}

void NewGameMenuState::update(const float& dt) {
    this->updateKeybinds();
    this->updateMousePosition();
    //std::cout << this->mousePosWindow.x << ", " << this->mousePosWindow.y << std::endl;
    updateButton();
}

void NewGameMenuState::renderButton(sf::RenderTarget& target) {
    for (auto& it : this->btns)
    {
        it.second->render(target);
    }
}

void NewGameMenuState::render(sf::RenderTarget& target) {
    target.draw(this->background);
    renderButton(target);
}

