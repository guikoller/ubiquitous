#include "EntityList.h"

EntityList::EntityList() {
    
}

EntityList::~EntityList() {
    destroy();
}

void EntityList::add(Entity* ent) {
    if (ent != nullptr)
        entities.addElementBack(ent);
}

void EntityList::remove(Entity* ent) {
    if (ent != nullptr)
        entities.removeFirstMatchingElement(ent);
}

void EntityList::destroy() {
    
}

EntityList::iterator EntityList::begin() {
    return entities.begin();
}

EntityList::iterator EntityList::end() {
    return entities.end();
}

void EntityList::move(const float& dt) {
    for (iterator i = entities.begin(); i != entities.end(); ++i) {
        (*i)->move(dt, 10, 0);
    }
}

void EntityList::update(const float& dt) {
    move(dt);
    for (iterator i = entities.begin(); i != entities.end(); ++i) {
        (*i)->update(dt);
    }
}

void EntityList::render(sf::RenderTarget& target) {
    for (iterator i = entities.begin(); i != entities.end(); ++i) {

        (*i)->render(target);
    }
}