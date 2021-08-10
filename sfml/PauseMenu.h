#pragma once
#include "Button.h"

class PauseMenu
{
private:
	sf::Font& font;
	sf::Text menuText;


	sf::RectangleShape bg;
	sf::RectangleShape container;

	std::map<std::string, Button*> buttons;

public:
	PauseMenu(sf::RenderWindow& window, sf::Font &font);
	virtual ~PauseMenu();
	
	void update();
	void render(sf::RenderTarget& target);
};