#include "GameMenuState.h"

void GameMenuState::initButton() {

    this->btns["NEW"] = new Button(300, 350, 220, 80, "new", &this->font,
        sf::Color(0, 0, 0, 230),
        sf::Color(10, 10, 10, 200),
        sf::Color(20, 20, 20, 150));

    this->btns["LOAD"] = new Button(300, 450, 220, 80, "load game", &this->font,
        sf::Color(0, 0, 0, 230),
        sf::Color(10, 10, 10, 200),
        sf::Color(20, 20, 20, 150));

    this->btns["QUIT"] = new Button(300, 550, 220, 80, "<-", &this->font,
        sf::Color(0, 0, 0, 230),
        sf::Color(10, 10, 10, 200),
        sf::Color(20, 20, 20, 150));

}

void GameMenuState::initBackground() {
    if (!this->texture.loadFromFile("Resources/Images/bg.png"))
        printf("BACKGROUND NÃO CARREGADO\n");

    this->background.setTexture(this->texture);
    this->background.setScale(1.8f, 1.5f);

}

GameMenuState::GameMenuState(sf::RenderWindow* window, std::stack<State*>* states) :State(window, states) {
    initBackground();
    initButton();
}

GameMenuState::~GameMenuState()
{
    auto it = this->btns.begin();

    for (it = this->btns.begin(); it != this->btns.end(); ++it)
    {
        delete it->second;
    }


}

void GameMenuState::updateButton() {
    for (auto& it : this->btns)
    {
        it.second->update(this->mousePosView);
    }

    // SAIR DO JOGO
    if (this->btns["QUIT"]->isPressed())
    {
        this->quit = true;
    }
    else if (this->btns["NEW"]->isPressed())
    {
        // PUSH NOVO STATE
        this->states->push(new GameState(this->window, this->states));
        printf("Button  inicar precionado\n");
    }
    else if (this->btns["LOAD"]->isPressed())
    {
        //this->states->push(new Pontuacao(this->window, this->states));
        printf("Button  placar precionado\n");
    }


}

void GameMenuState::update(const float& dt) {
    this->updateKeybinds();
    this->updateMousePosition();
    std::cout << this->mousePosWindow.x << ", " << this->mousePosWindow.y << std::endl;
    updateButton();
}

void GameMenuState::renderButton(sf::RenderTarget& target) {
    for (auto& it : this->btns)
    {
        it.second->render(target);
    }
}

void GameMenuState::render(sf::RenderTarget& target) {
    target.draw(this->background);
    renderButton(target);
}

