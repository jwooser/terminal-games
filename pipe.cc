#include "pipe.h"
#include <memory>
#include "staticSprite.h"
#include "properties.h"

void Pipe::setSize(int h, bool top) {
    addSprite(std::make_unique<StaticSprite>(Bitmap{3,h,'%'}));
    setBounds(3, h);
    if (top) {
        setPosition(79, 1);
    } else {
        setPosition(79, Properties::BORDER_HEIGHT - h);
    }
}

void Pipe::initialize(Game &game) {
    setCollisionLayer(0b0000000000000001);
    setVelocity(-1, 0);
}

void Pipe::process(Game &game) { }

void Pipe::collideX(Entity *other) { }

void Pipe::collideY(Entity *other) { }

void Pipe::collide(Border b) { }

void Pipe::pass(Entity *other) { }
