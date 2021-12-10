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

void ARLG::initialize(Game &game) {
    srand(time(NULL));
    toggleSolidBorder(true);
    p = queueSpawn(std::make_unique<Player>(), 1);
    p->setPosition(39, 18);
	queueSpawn(std::make_unique<Fire>(), 1)->setPosition(39, 8);
    queueSpawn(std::make_unique<Popup>(), 1)->setPosition(29, 3);
    queueSpawn(std::make_unique<Popup>(), 1)->setPosition(49, 13);
    Stalker *s = queueSpawn(std::make_unique<Stalker>(), 1);
	s->setPosition(19, 8);
	s->trackPlayer(p);
    s = queueSpawn(std::make_unique<Stalker>(), 1);
	s->setPosition(59, 8);
	s->trackPlayer(p);
    queueSpawn(std::make_unique<Walker>(), 1)->setPosition(19, 18);
    queueSpawn(std::make_unique<Snake>(), 1)->setPosition(59, 18);
}

void ARLG::process(Game &game) {
}
