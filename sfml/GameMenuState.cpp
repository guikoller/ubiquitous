#include "GameMenuState.h"

void GameMenuState::addName()
{
    system("CLS");
    printf("Enter your name:\n");
    std::cin >> name;
    std::cout << "Hello " << name << "\n";
}

void GameMenuState::initButton() {


    this->btns["ADD"] = new Button(550, 300, 480, 80, "name", &this->font,
        sf::Color(0, 0, 0, 230),
        sf::Color(10, 10, 10, 200),
        sf::Color(20, 20, 20, 150));

    this->btns["1"] = new Button(550, 450, 220, 80, "I", &this->font,
        sf::Color(0, 0, 0, 230),
        sf::Color(10, 10, 10, 200),
        sf::Color(20, 20, 20, 150));

    this->btns["2"] = new Button(800, 450, 220, 80, "II", &this->font,
        sf::Color(0, 0, 0, 230),
        sf::Color(10, 10, 10, 200),
        sf::Color(20, 20, 20, 150));

    this->btns["QUIT"] = new Button(100, 800, 220, 80, "back", &this->font,
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
    else if (this->btns["1"]->isPressed())
    {
        // PUSH NOVO STATE
        this->states->push(new FirstGameState(this->window, this->states));
        printf("Button  inicar precionado\n");
    }
    else if (this->btns["2"]->isPressed())
    {
        this->states->push(new SecondGameState(this->window, this->states));
        printf("Button  inicar precionado\n");
    }
    if (this->btns["ADD"]->isPressed())
    {
        addName();
        save();
    }
}

void GameMenuState::update(const float& dt) {
    this->updateKeybinds();
    this->updateMousePosition();
    //std::cout << this->mousePosWindow.x << ", " << this->mousePosWindow.y << std::endl;
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

void GameMenuState::save()
{
    file.open("Saves/score.txt", std::ios::app);
    file << name << ": ";
    file.close();
}

