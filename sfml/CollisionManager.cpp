#include "CollisionManager.h"

CollisionManager::CollisionManager() {
	this->ent = NULL;
	this->list = NULL;
}

CollisionManager::~CollisionManager()
{
}

void CollisionManager::add(Entity::Player::Player* ent, EntityList* list) {
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
			
			if (list->getElement(i)->getID() == 2)
			{
				if (clock.getElapsedTime().asSeconds()>1)
				{
					ent->addLife(-10);
				}
				clock.restart();
			}
			else if (list->getElement(i)->getID() == 3) {
				ent->setPosition(100, 100);
			}else{
				//bottom
				if (playerBounds.top < entBounds.top
					&& playerBounds.top + playerBounds.height < entBounds.top + entBounds.height
					&& playerBounds.left < entBounds.left + entBounds.width
					&& playerBounds.left + playerBounds.width > entBounds.left
					)
				{
					if (list->getElement(i)->getID() == 4 || list->getElement(i)->getID() == 5|| list->getElement(i)->getID() == 6) {
						list->getElement(i)->setPosition(10000, 1000);
					}
						
					
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
					if(list->getElement(i)->getID() != 1)
						ent->addLife(-10);
				}
				//right
				else if (playerBounds.left < entBounds.left
					&& playerBounds.left + playerBounds.width < entBounds.left + entBounds.width
					&& playerBounds.top < entBounds.top + entBounds.height
					&& playerBounds.top + playerBounds.height > entBounds.top
					)
				{
					this->ent->movementComponent->stopVelocityX();
					this->ent->hitboxComponent->setPosition(ent->hitboxComponent->getPosition().x-1, playerBounds.top);
					printf("colisão direita\n");
					if (list->getElement(i)->getID() != 1)
						ent->addLife(-10);
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
					if (list->getElement(i)->getID() != 1)
						ent->addLife(-10);
				}
			}
			
		}
	}
}