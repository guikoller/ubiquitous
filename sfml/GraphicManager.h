#pragma once
#include <SFML/Graphics.hpp>
class GraphicManager
{
private:

public:
	GraphicManager();
	~GraphicManager();

	void render(sf::RenderWindow& target, sf::Sprite* sprite, sf::RectangleShape* rect);
};


