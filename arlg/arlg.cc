#include "arlg.h"
#include <memory>
#include <cstdlib>
#include <ctime>
#include "fire.h"
#include "walker.h"
#include "popup.h"
#include "stalker.h"
#include "snake.h"
#include <string>


void ARLG::spawnWalker(int x, int y) {
    Entity* enemy = queueSpawn(std::make_unique<Walker>(), 1);
    enemy->setPosition(x, y);
    enemies.push_back(enemy);
}

void ARLG::spawnStalker(int x, int y) {
    Stalker* enemy = queueSpawn(std::make_unique<Stalker>(), 1);
	enemy->trackPlayer(p);
    enemy->setPosition(x, y);
    enemies.push_back(enemy);

}

void ARLG::spawnPopup(int x, int y) {
    Entity* enemy = queueSpawn(std::make_unique<Popup>(), 1);
    enemy->setPosition(x, y);
    enemies.push_back(enemy);
}

void ARLG::spawnSnake(int x, int y) {
    Entity* enemy = queueSpawn(std::make_unique<Snake>(), 1);
    enemy->setPosition(x, y);
    enemies.push_back(enemy);
}

void ARLG::loadLevel() {
    if (p) playerhp = p->gethp();
    queueDestroyAll();
    p = queueSpawn(std::make_unique<Player>(), 1);
    p->heal(playerhp);
    p->setPosition(39, 18);
    e = queueSpawn(std::make_unique<Exit>(), 1);
    e->setPosition(12, 12);

}

void ARLG::initialize(Game &game) {
    srand(time(NULL));
    toggleSolidBorder(true);
    loadLevel();
}

void ARLG::process(Game &game) {
    auto it = enemies.begin();
    while (it != enemies.end()){
        if((*it)->isFlaggedDestroy()){
            it = enemies.erase(it);
        } else ++it;
    }
    if (enemies.empty()) {
        e->openExit();
    }
    if (e->isExited()) {
        ++level;
        loadLevel();
    }
}
