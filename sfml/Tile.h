#pragma once
#include "Entity.h"

class Tile : virtual public Entity {
private:
	bool solid;

	void initVariables();
	void initComponents();
public:
	Tile(float x, float y, sf::Texture& texture_sheet, sf::IntRect texture_rect, bool solid);
	virtual ~Tile();

	const bool isSolid()const;
	void update(const float& dt);
	void save();
};