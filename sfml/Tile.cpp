#include "Tile.h"
namespace Entity {
	//INITIALIZER FUNCTIONS
	void Tile::initVariables() {

	}
	void Tile::initComponents() {

	}

	//CONSTRUCTORS DESTRUCTORS
	Tile::Tile(float x, float y, sf::Texture& texture_sheet, sf::IntRect texture_rect, bool solid) {
		this->solid = solid;

		initVariables();

		setPosition(x, y);

		createHitboxComponent(this->sprite, 0, 0, 64, 64);
		if (!solid)
			hitboxComponent->setColor(sf::Color(255, 0, 0, 100));

		this->sprite.setTexture(texture_sheet);
		this->sprite.setTextureRect(texture_rect);

		setSPriteScale(sf::Vector2f(2.f, 2.f));

	}
	Tile::~Tile() {

	}

	const bool Tile::isSolid() const {
		return solid;
	}


	void Tile::update(const float& dt) {
		this->hitboxComponent->update();
	}

	void Tile::save()
	{
	}
}



