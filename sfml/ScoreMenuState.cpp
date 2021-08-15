#include "ScoreMenuState.h"
namespace State {
    namespace Menu {
        void ScoreMenuState::initButton() {
            this->btns["QUIT"] = new Button(100, 800, 220, 80, "quit", &this->font,
                sf::Color(0, 0, 0, 230),
                sf::Color(10, 10, 10, 200),
                sf::Color(20, 20, 20, 150));
        }

        void ScoreMenuState::initBackground() {
            if (!this->texture.loadFromFile("Resources/Images/bg.png"))
                printf("BACKGROUND N�O CARREGADO\n");

            this->background.setTexture(this->texture);
            this->background.setScale(1.8f, 1.5f);

        }


        void ScoreMenuState::initTitle() {
            this->title.setFont(this->font);
            this->title.setString("scores");
            this->title.setCharacterSize(150);
            //this->title.setColor(sf::Color(250, 250, 250, 250));
            this->title.setPosition(sf::Vector2f(100, 50));
        }

        void ScoreMenuState::initScore()
        {
            std::string scores = readFile();

            this->scores.setFont(this->font);
            this->scores.setString(scores);
            this->scores.setFillColor(sf::Color::White);
            this->scores.setCharacterSize(45);
            this->scores.setPosition(sf::Vector2f(800, 50));
        }

        ScoreMenuState::ScoreMenuState(sf::RenderWindow* window, std::stack<State*>* states) :State(window, states) {
            initTitle();
            initBackground();
            initButton();
            initScore();
        }

        ScoreMenuState::~ScoreMenuState()
        {
            auto it = this->btns.begin();

            for (it = this->btns.begin(); it != this->btns.end(); ++it)
            {
                delete it->second;
            }
        }

        void ScoreMenuState::updateButton() {
            for (auto& it : this->btns)
            {
                it.second->update(this->mousePosView);
            }

            // SAIR DO JOGO
            if (this->btns["QUIT"]->isPressed())
            {
                this->quit = true;
            }
        }

        void ScoreMenuState::update(const float& dt) {
            this->updateKeybinds();
            this->updateMousePosition();
            //std::cout << this->mousePosWindow.x << ", " << this->mousePosWindow.y << std::endl;
            updateButton();
        }

        void ScoreMenuState::renderButton(sf::RenderTarget& target) {
            for (auto& it : this->btns)
            {
                it.second->render(target);
            }
        }

        void ScoreMenuState::render(sf::RenderTarget& target) {
            target.draw(this->background);
            renderButton(target);
            target.draw(this->title);
            target.draw(scores);
        }

        std::string ScoreMenuState::readFile() {
            std::ifstream inFile;
            inFile.open("Saves/score.txt"); //open the input file

            std::stringstream strStream;
            strStream << inFile.rdbuf(); //read the file
            std::string str = strStream.str(); //str holds the content of the file

            std::cout << str << "\n"; //you can do anything with the string!!!
            return str;
        }
    }
}