#include "floppybrad.h"
#include <memory>
#include <cstdlib>
#include <ctime>
#include "action.h"
#include "point.h"
#include <string>
#include <vector>

void ARLG::initialize(Game &game) {
    srand(time(NULL));
    toggleSolidBorder(false);
    brad = queueSpawn(std::make_unique<Brad>());
    brad->setPosition(15, 10);
}

void ARLG::process(Game &game) {
    
}


