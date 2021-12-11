#ifndef EXIT_H
#define EXIT_H

#include "entity.h"
#include "border.h"
#include "game.h"
#include "point.h"

class Exit : public Entity {

    bool open = false;
    bool exited = false;

    void initialize(Game &game) override;
    void process(Game &game) override;
    void collideX(Entity *other);
    void collideY(Entity *other) override;
    void collideB(Border b) override;
    void passEntity(Entity *other) override;

  public:
    void openExit();
    bool isExited();

};

#endif
