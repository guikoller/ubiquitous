#include "EntityList.h"

EntityList::EntityList() {

}

EntityList::~EntityList() {
    //delete();
}

void EntityList::add(Entity* ent) {

}

void EntityList::remove(Entity* ent) {
    //if(ent!= nullptr)
     //   entities.erase
}

void EntityList::initEntities(State* state) {

}

void EntityList::destroy() {
    for (iterator i = entities.begin(); i != entities.end(); i++)
    {
        entities.erase(i);
        delete (*i);        
    }
}


EntityList::iterator EntityList::begin() {
    return entities.begin();
}

EntityList::iterator EntityList::end() {
    return entities.end();
}


void EntityList::update(const float& dt) {
    for (iterator i = entities.begin(); i != entities.end(); i++)
    {
        (*i)->update(dt);
    }
}
void EntityList::render(sf::RenderTarget& target) {
    for (iterator i = entities.begin(); i != entities.end(); i++)
    {
        (*i)->render(target);
    }
}