#include "TileMap.h"

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
	initTextures();
	createMap();
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

void TileMap::createMap() {
	this->map.clear();

	sf::IntRect tijolo = sf::IntRect(32, 256, 32, 32);
	sf::IntRect parede_esq = sf::IntRect(64, 32, 32, 32);
	sf::IntRect parede_dir = sf::IntRect(0, 32, 32, 32);
	sf::IntRect teto = sf::IntRect(32, 64, 32, 32);
	sf::IntRect chao = sf::IntRect(32, 0, 32, 32);
	sf::IntRect canto_s_e = sf::IntRect(192, 0, 32, 32);
	sf::IntRect canto_s_d = sf::IntRect(224, 0, 32, 32);
	sf::IntRect canto_i_e = sf::IntRect(192, 32, 32, 32);
	sf::IntRect canto_i_d = sf::IntRect(224, 32, 32, 32);
	sf::IntRect chao2 = sf::IntRect(32, 128, 32, 32);

	std::vector<Tile*> Linha;

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{

			if (i == 0 && j == 0)//canto superior esquerdo
			{
				Linha.push_back(new Tile(i * 64.f, j * 64.f, this->texture, canto_s_e, true));
			}
			else if (i == 0 && (j + 1) == height)//canto inferior esquerdo
			{
				Linha.push_back(new Tile(i * 64.f, j * 64.f, this->texture, canto_i_e, true));
			}
			else if (j == 0 && (i + 1) == width)//canto inferior esquerdo
			{
				Linha.push_back(new Tile(i * 64.f, j * 64.f, this->texture, canto_s_d, true));
			}
			else if ((i + 1) == width && (j + 1) == height)//canto inferior direito
			{
				Linha.push_back(new Tile(i * 64.f, j * 64.f, this->texture, canto_i_d, true));
			}
			else if (i == 0)//parede esquerda
			{
				Linha.push_back(new Tile(i * 64.f, j * 64.f, this->texture, parede_esq, true));
			}
			else if (j == 0)//teto
			{
				Linha.push_back(new Tile(i * 64.f, j * 64.f, this->texture, teto, true));
			}
			else if (j + 1 == height)//chão
			{
				Linha.push_back(new Tile(i * 64.f, j * 64.f, this->texture, chao, true));
			}
			else if (i + 1 == width)//parede direita
			{
				Linha.push_back(new Tile(i * 64.f, j * 64.f, this->texture, parede_dir, true));
			}
			else if ((i > 0 && i < 20 && j == 9) || (i > 5 && i < 25 && j == 4))//chão 2
			{
				Linha.push_back(new Tile(i * 64.f, j * 64.f, this->texture, chao2, true));
			}
			else //tijolo parede
			{
				Linha.push_back(new Tile(i * 64.f, j * 64.f, this->texture, tijolo, false));
			}


		}
		this->map.push_back(Linha);
		Linha.clear();
	}

}

void TileMap::updateCollision(Player *player, const float&dt) {
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
						player->hitboxComponent->setPosition(tileBounds.left + tileBounds.width, playerBounds.top);
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
						player->hitboxComponent->setPosition(tileBounds.left - playerBounds.width, playerBounds.top);
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