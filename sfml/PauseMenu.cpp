#include "PauseMenu.h"

PauseMenu::PauseMenu(sf::RenderWindow& window, sf::Font& font) :font(font) {
	bg.setSize(sf::Vector2f(
			static_cast<float>(window.getSize().x), 
			static_cast<float>(window.getSize().y)
		)
	);
	
	bg.setFillColor(sf::Color(20, 20, 20, 100));
	
	container.setSize(sf::Vector2f(
			static_cast<float>(window.getSize().x) / 4.f,
			static_cast<float>(window.getSize().y)
		)
	);

	container.setFillColor(sf::Color(20, 20, 20, 200));
	container.setPosition(
		static_cast<float>(window.getSize().x) / 2.f - container.getSize().x / 2.f, 
		0.f
	);

	//INIT TEXT
	menuText.setFont(font);
	menuText.setFillColor(sf::Color(255,255,255,200));
	menuText.setCharacterSize(60);

	menuText.setString("PAUSED");
	menuText.setPosition(
		container.getPosition().x + container.getSize().x / 2.f - menuText.getGlobalBounds().width / 2.f,
		container.getPosition().y + 40.f
	);
}


PauseMenu::~PauseMenu() {
	
	auto it = this->buttons.begin();

	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}

}

std::map<std::string, Button*>& PauseMenu::getButtons()
{
	return this->buttons;
}

//Functions
const bool PauseMenu::isButtonPressed(const std::string key)
{
	return this->buttons[key]->isPressed();
}

void PauseMenu::addButton(
	const std::string key,
	const float y,
	const std::string text)
{
	float width = 250.f;
	float heigth = 80.f;
	float x = this->container.getPosition().x + this->container.getSize().x / 2.f - width / 2.f;

	this->buttons[key] = new Button(x, y, width, heigth, text, &this->font,
		sf::Color(0, 0, 0, 230),
		sf::Color(10, 10, 10, 200),
		sf::Color(20, 20, 20, 150));

}

void PauseMenu::update(const sf::Vector2f& mousePos) {
	for (auto& it : this->buttons)
	{
		it.second->update(mousePos);
	}
}

void PauseMenu::render(sf::RenderTarget& target) {

	target.draw(bg);
	target.draw(container);
	target.draw(menuText);

	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}

	
}