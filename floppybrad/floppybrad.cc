#include "floppybrad.h"
#include <memory>
#include <cstdlib>
#include <ctime>
#include "action.h"
#include "point.h"
#include <string>
#include <vector>

void FloppyBrad::initialize(Game &game) {
    srand(time(NULL));
    toggleSolidBorder(true);
    brad = queueSpawn(std::make_unique<Brad>());
    brad->setPosition(15, 10);
}

void FloppyBrad::process(Game &game) {
    
}


