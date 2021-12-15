#include "message.h"
#include <vector>
#include "staticSprite.h"
#include "point.h"

void Win::initialize(Game &game) {
    addSprite(std::make_unique<StaticSprite>(Bitmap{vector<Pixel> {
        Pixel(0, 0, 'C'), Pixel(1, 0, 'O'), Pixel(2, 0, 'N'), Pixel(3, 0, 'G'), Pixel(4, 0, 'L'),
        Pixel(5, 0, 'A'), Pixel(6, 0, 'T'), Pixel(7, 0, 'U'), Pixel(8, 0, 'R'), Pixel(9, 0, 'A'),
        Pixel(10, 0, 'T'), Pixel(11, 0, 'I'), Pixel(12, 0, 'O'), Pixel(13, 0, 'N'),
        Pixel(15, 0, '!'), Pixel(16, 0, '!'), Pixel(17, 0, '!'),
        Pixel(0, 2, 'Y'), Pixel(1, 2, 'O'), Pixel(2, 2, 'U'), Pixel(4, 2, 'H'),
        Pixel(5, 2, 'A'), Pixel(6, 2, 'V'), Pixel(7, 2, 'E'), Pixel(9, 2, 'C'),
        Pixel(10, 2, 'O'), Pixel(11, 2, 'M'), Pixel(12, 2, 'P'), Pixel(13, 2, 'L'), 
        Pixel(14, 2, 'E'), Pixel(15, 2, 'T'), Pixel(16, 2, 'E'), Pixel(17, 2, 'D')
        Pixel(2, 3, 'A'), Pixel(5, 3, 'G'), Pixel(6, 3, 'R'), Pixel(7, 3, 'E'), Pixel(8, 3, 'A'),
        Pixel(9, 3, 'T'), Pixel(11, 3, 'G'), Pixel(12, 3, 'A'), Pixel(13, 3, 'M'), 
        Pixel(14, 3, 'E'), Pixel(15, 3, '.')
    }}));
    setPosition(31, 10);
}

void Win::process(Game &game) { }

void Win::collideX(Entity *other) { }

void Win::collideY(Entity *other) { }

void Win::collide(Border b) { }

void Win::pass(Entity *other) { }

void Lose::initialize(Game &game) {
    addSprite(std::make_unique<StaticSprite>(Bitmap{vector<Pixel> {
        Pixel(0, 0, 'Y'), Pixel(1, 0, 'O'), Pixel(2, 0, 'U'),
        Pixel(4, 0, 'L'), Pixel(5, 0, 'O'), Pixel(6, 0, 'S'), Pixel(7, 0, 'E'), 
    }}));
    setPosition(37, 10);
}

void Lose::process(Game &game) { }

void Lose::collideX(Entity *other) { }

void Lose::collideY(Entity *other) { }

void Lose::collide(Border b) { }

void Lose::pass(Entity *other) { }
