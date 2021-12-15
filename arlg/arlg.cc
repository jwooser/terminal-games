#include "arlg.h"
#include <memory>
#include <cstdlib>
#include <ctime>
#include "action.h"
#include "fire.h"
#include "walker.h"
#include "popup.h"
#include "stalker.h"
#include "snake.h"
#include "point.h"
#include "boss.h"
#include <string>
#include <vector>

void ARLG::setLevel(size_t l) { level = l; }

void ARLG::spawnWalker(int x, int y) {
    Entity* enemy = queueSpawn(std::make_unique<Walker>());
    enemy->setPosition(x, y);
    enemies.push_back(enemy);
}

void ARLG::spawnStalker(int x, int y) {
    Stalker* enemy = queueSpawn(std::make_unique<Stalker>());
	enemy->trackPlayer(p);
    enemy->setPosition(x, y);
    enemies.push_back(enemy);
}

void ARLG::spawnPopup(int x, int y) {
    Entity* enemy = queueSpawn(std::make_unique<Popup>());
    enemy->setPosition(x, y);
    enemies.push_back(enemy);
}

void ARLG::spawnSnake(int x, int y) {
    Entity* enemy = queueSpawn(std::make_unique<Snake>());
    enemy->setPosition(x, y);
    enemies.push_back(enemy);
}

void ARLG::spawnBoss(int x, int y) {
    Entity* enemy = queueSpawn(std::make_unique<Boss>());
    enemy->setPosition(x, y);
    enemies.push_back(enemy);
}

void ARLG::loadLevel() {
    if (p) playerhp = p->gethp();
    queueDestroyAll();
    p = queueSpawn(std::make_unique<Player>());
    std::vector<Point> pos = {{39, 19}, {13, 7}, {57, 13}, {21, 3}, {29, 17}, {17, 15}, {71, 11}, {63, 5}};
    p->heal(playerhp);
    size_t ppos = rand() % pos.size();
    pos.erase(pos.begin() + ppos);
    p->setPosition(pos[rand() % 8]);
    e = queueSpawn(std::make_unique<Exit>());
    size_t epos = rand() % pos.size();
    e->setPosition(pos[epos]);
    if (level == 1) loadLevel1();
    else if (level == 2) loadLevel2();
    else if (level == 3) loadLevel3();
    else if (level == 4) loadLevel4();
    else if (level == 5) loadLevel5();
    else if (level == 6) loadLevel6();
}

void ARLG::loadLevel1() {
    std::vector<Point> pos;
    for (int x = 6; x < 74; x += 4) {
        for (int y = 4; y < 16; y += 4) {
            pos.push_back(Point{x, y});
        }
    }
    for (int i = 0; i < 6; ++i) {
        size_t temp = rand() % pos.size();
        Point spos = pos[temp];
        pos.erase(pos.begin() + temp);
        spawnWalker(spos.x, spos.y);
    }
    for (int i = 0; i < 6; ++i) {
        size_t temp = rand() % pos.size();
        Point spos = pos[temp];
        pos.erase(pos.begin() + temp);
        queueSpawn(std::make_unique<Fire>())->setPosition(spos);
    }
}

void ARLG::loadLevel2() {
	std::vector<Point> pos;
    for (int x = 6; x < 74; x += 4) {
        for (int y = 4; y < 16; y += 4) {
            pos.push_back(Point{x, y});
        }
    }
    for (int i = 0; i < 4; ++i) {
        size_t temp = rand() % pos.size();
        Point spos = pos[temp];
        pos.erase(pos.begin() + temp);
        spawnWalker(spos.x, spos.y);
    }
	for (int i = 0; i < 4; ++i) {
        size_t temp = rand() % pos.size();
        Point spos = pos[temp];
        pos.erase(pos.begin() + temp);
        spawnStalker(spos.x, spos.y);
    }

    for (int i = 0; i < 6; ++i) {
        size_t temp = rand() % pos.size();
        Point spos = pos[temp];
        pos.erase(pos.begin() + temp);
        queueSpawn(std::make_unique<Fire>())->setPosition(spos);
    }    
}

void ARLG::loadLevel3() {
	std::vector<Point> pos;
    for (int x = 6; x < 74; x += 4) {
        for (int y = 4; y < 16; y += 4) {
            pos.push_back(Point{x, y});
        }
    }
    for (int i = 0; i < 6; ++i) {
        size_t temp = rand() % pos.size();
        Point spos = pos[temp];
        pos.erase(pos.begin() + temp);
        spawnWalker(spos.x, spos.y);
    }
    for (int i = 0; i < 3; ++i) {
        size_t temp = rand() % pos.size();
        Point spos = pos[temp];
        pos.erase(pos.begin() + temp);
        spawnPopup(spos.x, spos.y);
    }

    for (int i = 0; i < 6; ++i) {
        size_t temp = rand() % pos.size();
        Point spos = pos[temp];
        pos.erase(pos.begin() + temp);
        queueSpawn(std::make_unique<Fire>())->setPosition(spos);
	}
}

void ARLG::loadLevel4() {
    std::vector<Point> pos;
    for (int x = 6; x < 74; x += 4) {
        for (int y = 4; y < 16; y += 4) {
            pos.push_back(Point{x, y});
        }
    }
    for (int i = 0; i < 6; ++i) {
        size_t temp = rand() % pos.size();
        Point spos = pos[temp];
        pos.erase(pos.begin() + temp);
        spawnStalker(spos.x, spos.y);
    }
    for (int i = 0; i < 3; ++i) {
        size_t temp = rand() % pos.size();
        Point spos = pos[temp];
        pos.erase(pos.begin() + temp);
        spawnSnake(spos.x, spos.y);
    }

    for (int i = 0; i < 4; ++i) {
        size_t temp = rand() % pos.size();
        Point spos = pos[temp];
        pos.erase(pos.begin() + temp);
        queueSpawn(std::make_unique<Fire>())->setPosition(spos);
    }
    
}

void ARLG::loadLevel5() {
	std::vector<Point> pos;
    for (int x = 6; x < 74; x += 4) {
        for (int y = 4; y < 16; y += 4) {
            pos.push_back(Point{x, y});
        }
    }
    for (int i = 0; i < 2; ++i) {
        size_t temp = rand() % pos.size();
        Point spos = pos[temp];
        pos.erase(pos.begin() + temp);
        spawnStalker(spos.x, spos.y);
    }
    for (int i = 0; i < 2; ++i) {
        size_t temp = rand() % pos.size();
        Point spos = pos[temp];
        pos.erase(pos.begin() + temp);
        spawnSnake(spos.x, spos.y);
    }
	for (int i = 0; i < 4; ++i) {
        size_t temp = rand() % pos.size();
        Point spos = pos[temp];
        pos.erase(pos.begin() + temp);
        spawnWalker(spos.x, spos.y);
    }
	for (int i = 0; i < 2; ++i) {
        size_t temp = rand() % pos.size();
        Point spos = pos[temp];
        pos.erase(pos.begin() + temp);
        spawnPopup(spos.x, spos.y);
    }

    for (int i = 0; i < 3; ++i) {
        size_t temp = rand() % pos.size();
        Point spos = pos[temp];
        pos.erase(pos.begin() + temp);
        queueSpawn(std::make_unique<Fire>())->setPosition(spos);
    }
 
}

void ARLG::loadLevel6() {
    p->setPosition(40, 18);
    spawnBoss(34, 4);
}

void ARLG::initialize(Game &game) {
    srand(time(NULL));
    toggleSolidBorder(true);
    loadLevel();
	game.updateStatus(0, "Level: " + std::to_string(level) + "/6");

}

void ARLG::process(Game &game) {
    auto it = enemies.begin();
    while (it != enemies.end()){
        if((*it)->isFlaggedDestroy()){
            it = enemies.erase(it);
        } else ++it;
    }
	if (game.getInput() == Action::L_TRIGGER) game.stop();
	if (e) {
    	if (enemies.empty()) {
        	e->openExit();
    	}
    	if (e->isExited()) {
			++level;
        	if (level > 6) {
				p = nullptr;
				e = nullptr;
				queueDestroyAll();
			}
			else {
				game.updateStatus(0, "Level: " + std::to_string(level) + "/6");
        		loadLevel();
			}
		}
    }
}
