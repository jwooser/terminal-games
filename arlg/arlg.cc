#include "arlg.h"
#include <memory>
#include <cstdlib>
#include <ctime>
#include "fire.h"
#include "walker.h"
#include "popup.h"
#include "stalker.h"
#include "snake.h"
#include "point.h"
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
    std::list<Point> pos = {{39, 18}, {13, 8}, {57, 12}, {21, 4}, {29, 16}, {17, 16}, {71, 12}, {63, 4}}
    p->heal(playerhp);
    size_t ppos = rand() % pos.size();
    pos.erase(ppos);
    p->setPosition(pos[rand() % 8]);
    e = queueSpawn(std::make_unique<Exit>(), 1);
    size_t epos = rand() % pos.size();
    e->setPosition(pos[epos]);
    if (level == 1) level1();
    else if (level == 2) level2();
    else if (level == 3) level3();
    else if (level == 4) level4();
    else if (level == 5) level5();
    else if (level == 6) level6();
}

void ARLG::level1() {
    std::list<Point> pos;
    for (int x = 6; x < 74; x += 4) {
        for (int y = 4; y < 16; y += 4) {
            pos.push_back(Point{x, y});
        }
    }
    for (int i = 0; i < 6; ++i) {
        size_t temp = rand() % pos.size();
        spos = pos[temp];
        pos.erase(temp);
        spawnWalker(spos.x, spos.y);
    }
}

void ARLG::level2() {
    
}

void ARLG::level3() {
    
}

void ARLG::level4() {
    
}

void ARLG::level5() {
    
}

void ARLG::level6() {
    
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
        if (level > 6) game.stop();
        ++level;
        loadLevel();
    }
}
