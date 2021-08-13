#include "MainMenu.h"

void MainMenu::initButton() {

    this->btns["START"] = new Button(700, 550, 220, 80, "start", &this->font,
        sf::Color(0, 0, 0, 230),
        sf::Color(10, 10, 10, 200),
        sf::Color(20, 20, 20, 150));
    this->btns["START"]->setTextYPosition(570.f);

    this->btns["PLACAR"] = new Button(700, 650, 220, 80, "leaderboard", &this->font,
        sf::Color(0, 0, 0, 230),
        sf::Color(10, 10, 10, 200),
        sf::Color(20, 20, 20, 150));
    this->btns["PLACAR"]->setTextYPosition(670.f);

    this->btns["SAIR"] = new Button(700, 750, 220, 80, "quit", &this->font,
        sf::Color(0, 0, 0, 230),
        sf::Color(10, 10, 10, 200),
        sf::Color(20, 20, 20, 150));

    this->btns["SAIR"]->setTextYPosition(767.f);
}

void MainMenu::initBackground() {
    if (!this->texture.loadFromFile("Resources/Images/bg.png"))
        printf("BACKGROUND N�O CARREGADO\n");

    this->background.setTexture(this->texture);
    this->background.setScale(1.8f, 1.5f);
    
}


void MainMenu::initTitle() {
    this->title.setFont(this->font);
    this->title.setString("Ubiquitous");
    this->title.setCharacterSize(150);
    //this->title.setColor(sf::Color(250, 250, 250, 250));
    this->title.setPosition(sf::Vector2f(385, 150));
}

MainMenu::MainMenu(sf::RenderWindow* window, std::stack<State*>* states) :State(window, states) {
    initTitle();
    initBackground();
    initButton();
}

MainMenu::~MainMenu()
{
    auto it = this->btns.begin();

    for (it = this->btns.begin(); it != this->btns.end(); ++it)
    {
        delete it->second;
    }


}

void MainMenu::updateButton() {
    for (auto& it : this->btns)
    {
        it.second->update(this->mousePosView);
    }

    // SAIR DO JOGO
    if (this->btns["SAIR"]->isPressed())
    {
        this->quit = true;
    }
    else if (this->btns["START"]->isPressed())
    {
        // PUSH NOVO STATE
        this->states->push(new GameMenuState(this->window, this->states));

    }
    else if (this->btns["PLACAR"]->isPressed())
    {
        //this->states->push(new Pontuacao(this->window, this->states));

    }


}

void MainMenu::update(const float& dt) {
    this->updateKeybinds();
    this->updateMousePosition();
    //std::cout << this->mousePosWindow.x << ", " << this->mousePosWindow.y << std::endl;
    updateButton();
}

void MainMenu::renderButton(sf::RenderTarget& target) {
    for (auto& it : this->btns)
    {
        it.second->render(target);
    }
}

void MainMenu::render(sf::RenderTarget& target) {
    target.draw(this->background);
    renderButton(target);
    target.draw(this->title);
}

