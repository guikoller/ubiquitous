#include "GraphicManager.h"
GraphicManager::GraphicManager()
{
}

GraphicManager::~GraphicManager()
{
}

void GraphicManager::render(sf::RenderWindow& target, sf::Sprite* sprite, sf::RectangleShape *rect) {
	if(sprite)
		target.draw(*sprite);
	else
		target.draw(*rect);
}