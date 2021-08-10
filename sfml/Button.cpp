#include "Button.h"

Button::Button(float x, float y, float width, float height, std::string text, sf::Font* font, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor) {
    this->btn_state = BTN_IDLE;

    this->shape.setSize(sf::Vector2f(width, height));
    this->shape.setPosition(sf::Vector2f(x, y));

    this->font = font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(30);
    this->text.setPosition(
        this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
        this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height
    );

    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->activeColor = activeColor;

    this->shape.setFillColor(this->idleColor);
}

Button::~Button() {}


const bool Button::isPressed() const{
    if (this->btn_state == BTN_PRESSED) {
        return true;
    }
    return false;
}

void Button::setTextYPosition(const float y){
    this->text.setPosition(sf::Vector2f(text.getPosition().x, y));
}

void Button::update(const sf::Vector2f& mousePos) {

    // ESTADO PADRÃO DO BOTÃO
    this->btn_state = BTN_IDLE;

    if (this->shape.getGlobalBounds().contains(mousePos)) {
        //PASSOU MOUSE POR CIMA
        this->btn_state = BTN_HOVER;
        //APERTOU BOTÃO
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            this->btn_state = BTN_PRESSED;
        }
    }

    switch (this->btn_state) {
    case BTN_IDLE:
        this->shape.setFillColor(this->idleColor);
        break;
    case BTN_HOVER:
        this->shape.setFillColor(this->hoverColor);
        break;
    case BTN_PRESSED:
        this->shape.setFillColor(this->activeColor);
        break;
    default:
        this->shape.setFillColor(sf::Color::Red);//não é pra entrar aqui não
        break;
    }


}

void Button::render(sf::RenderTarget& target) {
    target.draw(this->shape);
    target.draw(this->text);
}