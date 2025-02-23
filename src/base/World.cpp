#include "World.h"
#include "objects/Sphere.h"

void World::addObject(std::shared_ptr<Object> obj) {
    objs.push_back(obj);
}
