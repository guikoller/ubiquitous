#pragma once
#include "Entity.h"
namespace State {
    class State {
    public:
        std::stack<State*>* states;

        sf::RenderWindow* window;
        bool quit;
        bool paused;

        sf::Font font;

        sf::Vector2i mousePosScreen;
        sf::Vector2i mousePosWindow;
        sf::Vector2f mousePosView;

        std::ofstream file;

        //Resources
        std::map<std::string, sf::Texture> textures;

        void initFont();
    public:
        State(sf::RenderWindow* window, std::stack<State*>* states);
        virtual ~State();

        const bool& getQuit() const;

        virtual void checkQuit();

        virtual void endState();
        void pauseState();
        void unpauseState();

        virtual void updateMousePosition();

        virtual void updateKeybinds();
        virtual void update(const float& dt) = 0;
        virtual void render(sf::RenderTarget& target) = 0;
    };
}