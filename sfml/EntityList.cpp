#include "EntityList.h"

EntityList::EntityList() {

}

EntityList::~EntityList() {
    destroy();
}

void EntityList::add(Entity* ent) {
    entities.push_back(ent);
}

void EntityList::remove(Entity* ent) {

}

void EntityList::destroy() {
}





void EntityList::update(const float& dt) {

    for (auto& it : entities) {
        it->update(dt);
    }
}

void EntityList::render(sf::RenderTarget& target) {
    for (auto& it : entities) {
        it->render(target);
    }
}

const int EntityList::length()const {
    return this->entities.size();
}

Entity* EntityList::getElement(const int pos) {
    return entities.at(pos);
}