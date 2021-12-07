#include "world.h"
#include "solidPhysics.h"
#include "viewPhysics.h"

using std::make_unique;

World::World():
physics {std::make_unique<SolidPhysics>()}
{ }

void World::doInitialize(Game &game) {
    initialize(game);
	doEntitySpawns(game);
    doEntityRenders();
}

void World::doProcess(Game &game) {
    physics->step(entities);
    process(game);
	doEntityProcesses(game);
    doEntityDestroys();
    doEntitySpawns(game);
    doEntityRenders();
}

void World::toggleSolidBorder(bool solid) {
    if (solid) physics = make_unique<SolidPhysics>();
    else physics = make_unique<ViewPhysics>();
}

void World::queueRender(Entity *entity) {
    Point pos = entity->getPosition() + entity->getSpriteOffset();
    const Bitmap &sprite = entity->getSpriteFrame();
    render.emplace(pos, &sprite);
}

queue<pair<Point, const Bitmap*>>& World::getRender() {
    return render;
}

// ********************************************************************************
// ENTITY HELPER METHODS
// ********************************************************************************

void World::doEntityProcesses(Game &game) {
    for (auto &a : entities) {
        for (auto &b : a.second) {
            b->doProcess(game);
            while (!b->getSpawns().empty()) {
                spawns.emplace(std::move(b->getSpawns().front()), a.first);
                b->getSpawns().pop();
            }
        }
    }
}

void World::doEntityDestroys() {
    for (auto &a : entities) {
        auto b = a.second.begin();
        while (b != a.second.end()){
            if((*b)->isTaggedDestroy()){
                b = a.second.erase(b);
            } else ++b;
        }
    }
}

void World::doEntitySpawns(Game &game) {
    while (!spawns.empty()) {
        unique_ptr<Entity> entity = std::move(spawns.front().first);
        Entity * e = entity.get();
        int height = spawns.front().second;
        entities[height].push_back(std::move(entity));
        e->doInitialize(game);
        spawns.pop();
    }
}

void World::doEntityRenders() {
    for (auto &a : entities) {
        for (auto &b : a.second) {
            queueRender(b.get());
        }
    }
}
