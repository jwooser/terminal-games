#ifndef ARLG_H
#define ARLG_H

#include "world.h"
#include "action.h"
#include "player.h"

class ARLG : public World {
        size_t level = 1;
        Player *p;
        
        void initialize(Game &game) override;
        void process(Game &game) override;
};

#endif
