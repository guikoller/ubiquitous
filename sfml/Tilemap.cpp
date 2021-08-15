#include "TileMap.h"
namespace Entity {
	void TileMap::initTextures() {
		this->height = 14;
		this->width = 25;

		try
		{
			this->texture.loadFromFile("Resources/sprites/Tileset.png");
		}
		catch (const std::exception&)
		{
			throw("error loading tilemap texture");
		}
	}

	TileMap::TileMap() {
		//initTextures();
		//createMap();
	}

	const bool TileMap::isSolid(int x, int y)const {
		return this->map[x][y]->isSolid();
	}

	TileMap::~TileMap() {
		deleteMap();
	}

	void TileMap::deleteMap()
	{
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				delete map[i][j];
			}
		}
	}

	void TileMap::updateCollision(Player::Player* player, const float& dt) {
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				if (map[i][j]->isSolid()) {

					sf::FloatRect playerBounds = player->hitboxComponent->getGlobalBounds();
					sf::FloatRect tileBounds = this->map[i][j]->getGlobalBounds();

					if (this->map[i][j]->intersects(player->hitboxComponent->getNextPosition(player->movementComponent->getVelocity() * dt)))
					{
						//bottom
						if (playerBounds.top < tileBounds.top
							&& playerBounds.top + playerBounds.height < tileBounds.top + tileBounds.height
							&& playerBounds.left < tileBounds.left + tileBounds.width
							&& playerBounds.left + playerBounds.width > tileBounds.left
							)
						{
							player->movementComponent->stopVelocityY();
							player->hitboxComponent->setPosition(playerBounds.left, tileBounds.top - playerBounds.height);
							printf("colisão chão\n");
						}
						//top
						else if (playerBounds.top > tileBounds.top
							&& playerBounds.top + playerBounds.height > tileBounds.top + tileBounds.height
							&& playerBounds.left < tileBounds.left + tileBounds.width
							&& playerBounds.left + playerBounds.width > tileBounds.left
							)
						{
							player->movementComponent->stopVelocityX();
							player->hitboxComponent->setPosition(player->hitboxComponent->getPosition().x, player->hitboxComponent->getPosition().y - 10);
							printf("colisão topo\n");
						}
						//right
						else if (playerBounds.left < tileBounds.left
							&& playerBounds.left + playerBounds.width < tileBounds.left + tileBounds.width
							&& playerBounds.top < tileBounds.top + tileBounds.height
							&& playerBounds.top + playerBounds.height > tileBounds.top
							)
						{
							player->movementComponent->stopVelocityX();
							player->hitboxComponent->setPosition(player->hitboxComponent->getPosition().x - 20, player->hitboxComponent->getPosition().y - 20);
							printf("colisão direita\n");
						}
						//left
						else if (playerBounds.left > tileBounds.left
							&& playerBounds.left + playerBounds.width > tileBounds.left + tileBounds.width
							&& playerBounds.top < tileBounds.top + tileBounds.height
							&& playerBounds.top + playerBounds.height > tileBounds.top
							)
						{
							player->movementComponent->stopVelocityX();
							player->hitboxComponent->setPosition(tileBounds.left + tileBounds.width, playerBounds.top);
							printf("colisão esquerda\n");
						}
					}
				}

			}

		}
	}

	void TileMap::render(sf::RenderTarget& target) {
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				this->map[i][j]->render(target);
			}
		}
	}
}
