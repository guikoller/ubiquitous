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

void CollisionManager::update(const float &dt) {
	int length = list->length();
	for (int i = 0; i < length; i++)
	{
		sf::FloatRect playerBounds = this->ent->hitboxComponent->getGlobalBounds();
		sf::FloatRect entBounds = this->list->getElement(i)->getGlobalBounds();
		if (this->list->getElement(i)->intersects(ent->hitboxComponent->getNextPosition(ent->movementComponent->getVelocity() * dt)))
		{
			//bottom
			if (playerBounds.top < entBounds.top
				&& playerBounds.top + playerBounds.height < entBounds.top + entBounds.height
				&& playerBounds.left < entBounds.left + entBounds.width
				&& playerBounds.left + playerBounds.width > entBounds.left
				)
			{
				list->getElement(i)->setPosition(-400, -400);
				printf("colisão chão\n");
			}
			//top
			else if (playerBounds.top > entBounds.top
				&& playerBounds.top + playerBounds.height > entBounds.top + entBounds.height
				&& playerBounds.left < entBounds.left + entBounds.width
				&& playerBounds.left + playerBounds.width > entBounds.left
				)
			{
				this->ent->movementComponent->stopVelocityX();
				//this->ent->hitboxComponent->setPosition(entBounds.left + entBounds.width, playerBounds.top);
				printf("colisão topo\n");
			}
			//right
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
			//left
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