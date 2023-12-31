#include "stalker.h"
#include <cstdlib>
#include "staticSprite.h"
#include "point.h"
#include "player.h"
#include "walker.h"

void Stalker::trackPlayer(Player *p) { player = p; }

void Stalker::moveTowardsPlayer() {
    Point dist = player->getPosition() - getPosition();
    int ax = abs(dist.x);
    int ay = abs(dist.y);
    if (ax != 0 && ay != 0) {
		if (rand() % 2) {
            if (dist.x > 0) setVelocity(1, 0);
            else if (dist.x < 0) setVelocity(-1, 0);
        } else {
            if (dist.y > 0) setVelocity(0, 1);
            else if (dist.y < 0) setVelocity(0, -1);
        }
	} else if (ay != 0) {
        if (dist.y > 0) setVelocity(0, 1);
        else if (dist.y < 0) setVelocity(0, -1); 
    } else if (ax != 0 ){
		if (dist.x > 0) setVelocity(1, 0);
        else if (dist.x < 0) setVelocity(-1, 0);
	}
};

void Stalker::initialize(Game &game) {
    addSprite(std::make_unique<StaticSprite>(Bitmap{2,2,'b'}));
    setBounds(Point{2,2});
    setCollisionLayer(0b0000000000000100);
    setCollisionMask(0b0000000000000001);
	heal(2);
}

void Stalker::process(Game &game) {
	if (dead()) {
		if (rand() % 4 == 0) {
			queueSpawn(std::make_unique<Walker>())->setPosition(getPosition());
		}
		queueDestroy();
	}
	if (player) moveTowardsPlayer();
	if (game.getTick() % 12 > 10) setVelocity(0, 0);
}

void Stalker::collideX(Entity *other) { 
    if (auto p = dynamic_cast<Player*>(other)) {
        p->damage();
        doPush(-2 * getVelocity());
        p->doPush(getVelocity());
    }
}

void Stalker::collideY(Entity *other) { 
    if (auto p = dynamic_cast<Player*>(other)) {
        p->damage();
        doPush(-2 * getVelocity());
        p->doPush(getVelocity());
    }
}

void Stalker::collide(Border b) { }

void Stalker::pass(Entity *other) { }

