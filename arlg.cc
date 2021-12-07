#include "arlg.h"
#include <memory>

void ARLG::initialize(Game &game) {
    toggleSolidBorder(true);
    p = queueSpawn(std::make_unique<Player>, 1);
    p->setPosition(39, 18);
}

void ARLG::process(Game &game) {

}
