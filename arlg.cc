#include "arlg.h"
#include <memory>
#include <cstdlib>
#include <ctime>
#include "fire.h"
#include "walker.h"

void ARLG::initialize(Game &game) {
    srand(time(NULL));
    toggleSolidBorder(true);
    p = queueSpawn(std::make_unique<Player>(), 1);
    p->setPosition(39, 18);
	queueSpawn(std::make_unique<Fire>(), 1)->setPosition(39, 8);
    queueSpawn(std::make_unique<Fire>(), 1)->setPosition(29, 8);
    queueSpawn(std::make_unique<Fire>(), 1)->setPosition(49, 8);
    queueSpawn(std::make_unique<Fire>(), 1)->setPosition(19, 8);
    queueSpawn(std::make_unique<Fire>(), 1)->setPosition(59, 8);
    queueSpawn(std::make_unique<Walker>(), 1)->setPosition(19, 18);
    queueSpawn(std::make_unique<Walker>(), 1)->setPosition(59, 18);
}

void ARLG::process(Game &game) {

}
