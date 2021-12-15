#include "world.h"
#include <vector>
#include "solidPhysics.h"
#include "viewPhysics.h"
#include "body.h"

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
    doEntityPhysics();
	doEntityProcesses(game);
    process(game);
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

void World::queueDestroyAll() {
    for (auto &a : entities) {
        for (auto &b : a.second) {
            b->queueDestroy();
        }
    }
}

queue<pair<Point, const Bitmap*>>& World::getRender() {
    return render;
}

// ********************************************************************************
// ENTITY HELPER METHODS
// ********************************************************************************

void World::doEntityPhysics() {
    for (auto &a : entities) {
        std::vector<Body*> bodies;
        bodies.reserve(a.second.size());
        for (auto &b : a.second) bodies.push_back(b.get());
        physics->step(bodies);
    }
}

void World::collectSpawns(queue<pair<unique_ptr<Entity>, int>> &entitySpawns) {
    while (!entitySpawns.empty()) {
        spawns.push(std::move(entitySpawns.front()));
        entitySpawns.pop();
    }
}

void World::doEntityProcesses(Game &game) {
    for (auto &a : entities) {
        for (auto &b : a.second) {
            b->doProcess(game, {});
            collectSpawns(b->getSpawns());
        }
    }
}

void World::doEntityDestroys() {
    for (auto &a : entities) {
        auto b = a.second.begin();
        while (b != a.second.end()){
            if((*b)->isFlaggedDestroy()){
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
        e->doInitialize(game, height, {});
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
