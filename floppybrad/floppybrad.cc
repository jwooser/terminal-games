#include "floppybrad.h"
#include <memory>
#include <cstdlib>
#include <ctime>
#include "action.h"
#include "point.h"
#include "pipe.h"
#include "properties.h"
#include <string>
#include <vector>

void FloppyBrad::initialize(Game &game) {
    srand(time(NULL));
    toggleSolidBorder(true);
    brad = queueSpawn(std::make_unique<Brad>());
    brad->setPosition(15, 10);
}

void FloppyBrad::process(Game &game) {
    if (game.getTick() % 30 == 0) {
        int t = 2 + rand() % 12;
        queueSpawn(std::make_unique<Pipe>())->setSize(t, true);
        queueSpawn(std::make_unique<Pipe>())->setSize(Properties::BORDER_HEIGHT - t - 5);
    }
}


