#include "CollisionManager.h"

CollisionManager::CollisionManager() {
	this->ent = NULL;
	this->list = NULL;

}

CollisionManager::~CollisionManager()
{
}

void CollisionManager::add(Entity* ent, EntityList* list) {
	this->ent = ent;
	this->list = list;
}

void CollisionManager::update() {
	int length = list->length();
	for (size_t i = 0; i < length; i++)
	{
		sf::FloatRect playerBounds = this->ent->hitboxComponent->getGlobalBounds();
		sf::FloatRect entBounds = this->list->getElement(i)->getGlobalBounds();
		if (ent->intersects(entBounds))
		{
			//baixo
			if (playerBounds.top < entBounds.top
				&& playerBounds.top + playerBounds.height < entBounds.top + entBounds.height
				&& playerBounds.left < entBounds.left + entBounds.width
				&& playerBounds.left + playerBounds.width > entBounds.left
				)
			{
				this->ent->movementComponent->stopVelocityY();
				this->ent->hitboxComponent->setPosition(playerBounds.left, entBounds.top - playerBounds.height);
				printf("colisão chão\n");
			}
			// cima
			else if (playerBounds.top > entBounds.top
				&& playerBounds.top + playerBounds.height > entBounds.top + entBounds.height
				&& playerBounds.left < entBounds.left + entBounds.width
				&& playerBounds.left + playerBounds.width > entBounds.left
				)
			{
				this->ent->movementComponent->stopVelocityX();
				this->ent->hitboxComponent->setPosition(entBounds.left + entBounds.width, playerBounds.top);
				printf("colisão topo\n");
			}
			//direita
			else if (playerBounds.left < entBounds.left
				&& playerBounds.left + playerBounds.width < entBounds.left + entBounds.width
				&& playerBounds.top < entBounds.top + entBounds.height
				&& playerBounds.top + playerBounds.height > entBounds.top
				)
			{
				this->ent->movementComponent->stopVelocityX();
				this->ent->hitboxComponent->setPosition(entBounds.left - playerBounds.width, playerBounds.top);
				printf("colisão direita\n");
			}
			//esquerda
			else if (playerBounds.left > entBounds.left
				&& playerBounds.left + playerBounds.width > entBounds.left + entBounds.width
				&& playerBounds.top < entBounds.top + entBounds.height
				&& playerBounds.top + playerBounds.height > entBounds.top
				)
			{
				this->ent->movementComponent->stopVelocityX();
				this->ent->hitboxComponent->setPosition(entBounds.left + entBounds.width, playerBounds.top);
				printf("colisão esquerda\n");
			}
		}
	}
}