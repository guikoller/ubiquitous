#pragma once
#include <SFML/Graphics.hpp>
class Entity{
private:
	void initVariables();

protected:
	sf::Texture* texture;
	sf::Sprite* sprite;
	
	float movementSpeed;
public:
	Entity();
	virtual ~Entity();

	//Components functions
	void createSprite(sf::Texture* texture);


	//Functions
	virtual void setPosition(const float pos_x, const float pos_y);
	virtual void move(const float& dt, const float x, const float y);
	
	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget& target);
};

