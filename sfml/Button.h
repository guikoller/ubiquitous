#pragma once
#include <SFML/Graphics.hpp>



class Button {
private:
    enum button_state { BTN_IDLE = 0, BTN_HOVER, BTN_PRESSED };

    short unsigned int btn_state;

    sf::RectangleShape shape;
    sf::Font* font;
    sf::Text text;

    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;

public:
    Button(float x, float y, float width, float height, std::string text, sf::Font* font, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
    ~Button();

    //acessores
    const bool isPressed() const;

    //funções
    void setTextYPosition(const int y);
    void update(const sf::Vector2f mousePos);
    void render(sf::RenderTarget& target);
};