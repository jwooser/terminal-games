#ifndef ARLG_H
#define ARLG_H

#include "world.h"
#include <list>
#include "action.h"
#include "player.h"
#include "exit.h"

class ARLG : public World {
        size_t level = 1;
        Player *p = nullptr;
        Exit *e = nullptr;
        int playerhp = 5;
        std::list<Entity*> enemies;

        void spawnWalker(int x, int y);
        void spawnStalker(int x, int y);
        void spawnPopup(int x, int y);
        void spawnSnake(int x, int y);
        void loadLevel();

        void initialize(Game &game) override;
        void process(Game &game) override;
};

#endif
