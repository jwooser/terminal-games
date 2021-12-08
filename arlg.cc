#include "arlg.h"
#include <memory>
#include "fire.h"

void ARLG::initialize(Game &game) {
    toggleSolidBorder(true);
    p = queueSpawn(std::make_unique<Player>(), 1);
    p->setPosition(39, 18);
	queueSpawn(std::make_unique<Fire>(), 1)->setPosition(39, 8);
}

void ARLG::process(Game &game) {

}
