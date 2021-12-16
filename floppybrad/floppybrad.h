#ifndef FLOPPYBRAD_H
#define FLOPPYBRAD_H

#include "world.h"
#include <list>
#include "action.h"
#include "brad.h"

class FloppyBrad : public World {
    Brad *brad;
	size_t high = 0;

    void initialize(Game &game) override;
    void process(Game &game) override;
};

#endif
