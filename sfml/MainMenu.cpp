#include "MainMenu.h"

void MainMenu::initButton() {

    this->btns["START"] = new Button(700, 550, 200, 80, "initr", &this->fonte,
        sf::Color(0, 0, 0, 230),
        sf::Color(10, 10, 10, 200),
        sf::Color(20, 20, 20, 150));

    this->btns["PLACAR"] = new Button(700, 650, 200, 80, "Placar", &this->fonte,
        sf::Color(0, 0, 0, 230),
        sf::Color(10, 10, 10, 200),
        sf::Color(20, 20, 20, 150));

    this->btns["SAIR"] = new Button(700, 750, 200, 80, "Sair", &this->fonte,
        sf::Color(0, 0, 0, 230),
        sf::Color(10, 10, 10, 200),
        sf::Color(20, 20, 20, 150));
}

void MainMenu::initBackground() {
    /*if (!this->texture.loadFromFile("Textures/Background/bg.png"))
        printf("BACKGROUND N�O CARREGADO\n");

    this->background.setTexture(this->texture);
    this->background.setScale(6.f, 7.f);
    */
}


void MainMenu::initTitle() {
    this->title.setFont(this->fonte);
    this->title.setString("JOGASSO");
    this->title.setCharacterSize(300);
    this->title.setColor(sf::Color(250, 250, 250, 250));
    this->title.setPosition(sf::Vector2f(150, 100));
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
        //this->states->push(new MenuLevel(this->window, this->states));
        printf("Button  inicar precionado\n");
    }
    else if (this->btns["PLACAR"]->isPressed())
    {
        //this->states->push(new Pontuacao(this->window, this->states));
        printf("Button  placar precionado\n");
    }


}

void MainMenu::update() {
    this->updateKeybinds();
    this->updateMousePosition();
    std::cout << this->mousePosWindow.x << ", " << this->mousePosWindow.y << std::endl;
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
