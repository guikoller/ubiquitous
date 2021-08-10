#pragma once
#include "Button.h"

class PauseMenu
{
private:

	sf::RectangleShape bg;
	sf::RectangleShape container;

	std::map<std::string, Button*> buttons;

public:
	PauseMenu(sf::RenderWindow& window);
	virtual ~PauseMenu();
	
	void update();
	void render(sf::RenderTarget& target);
};