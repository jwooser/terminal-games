#include "boss.h"

void Boss::initialize(Game &game) {
    addSprite(std::make_unique<StaticSprite>(Bitmap{vector<Pixel> {
        Pixel(4, 0, '_'), Pixel(5, 0, '_'), Pixel(6, 0, '_'), Pixel(7, 0, '_'), Pixel(8, 0, '_'),
        Pixel(3, 1, ','), Pixel(4, 1, ' '), Pixel(5, 1, ' '), Pixel(6, 1, ' '), Pixel(7, 1, ' '), Pixel(8, 1, ' '), Pixel(9, 1, ','),
        Pixel(2, 2, '.'), Pixel(3, 2, ' '), Pixel(4, 2, ' '), Pixel(5, 2, ' '), Pixel(6, 2, ' '), Pixel(7, 2, ' '), Pixel(8, 2, ' '), Pixel(9, 2, ' '), Pixel(10, 2, '.'),
        Pixel(1, 3, '/'), Pixel(2, 3, ' '), Pixel(3, 3, ' '), Pixel(4, 3, 'o'), Pixel(5, 3, ' '), Pixel(6, 3, ' '), Pixel(7, 3, ' '), Pixel(8, 3, 'o'), Pixel(9, 3, ' '), Pixel(10, 3, ' '), Pixel(11, 3, '\\'),
        Pixel(0, 4, '|'), Pixel(1, 4, ' '), Pixel(2, 4, ' '), Pixel(3, 4, ' '), Pixel(4, 4, ' '), Pixel(5, 4, ' '), Pixel(6, 4, ' '), Pixel(7, 4, ' '), Pixel(8, 4, ' '), Pixel(9, 4, ' '), Pixel(10, 4, ' '), Pixel(11, 4, ' '), Pixel(12, 4, '|'),
        Pixel(0, 5, '|'), Pixel(1, 5, ' '), Pixel(2, 5, ' '), Pixel(3, 5, '\\'), Pixel(4, 5, ' '), Pixel(5, 5, ' '), Pixel(6, 5, ' '), Pixel(7, 5, ' '), Pixel(8, 5, ' '), Pixel(9, 5, '/'), Pixel(10, 5, ' '), Pixel(11, 5, ' '), Pixel(12, 5, '|'),
        Pixel(1, 6, '\\'), Pixel(2, 6, ' '), Pixel(3, 6, ' '), Pixel(4, 6, ','), Pixel(5, 6, '_'), Pixel(6, 6, '_'), Pixel(7, 6, '_'), Pixel(8, 6, ','), Pixel(9, 6, ' '), Pixel(10, 6, ' '), Pixel(11, 6, '/'),
        Pixel(2, 7, ','), Pixel(3, 7, ' '), Pixel(4, 7, ' '), Pixel(5, 7, ' '), Pixel(6, 7, ' '), Pixel(7, 7, ' '), Pixel(8, 7, ' '), Pixel(9, 7, ' '), Pixel(10, 7, ','),
        Pixel(3, 8, '.'), Pixel(4, 8, '_'), Pixel(5, 8, '_'), Pixel(6, 8, '_'), Pixel(7, 8, '_'), Pixel(8, 8, '_'), Pixel(9, 8, '.'),
    }}));
    addSprite(std::make_unique<StaticSprite>(Bitmap{vector<Pixel> {
        Pixel(4, 0, '_'), Pixel(5, 0, '_'), Pixel(6, 0, '_'), Pixel(7, 0, '_'), Pixel(8, 0, '_'),
        Pixel(3, 1, ','), Pixel(4, 1, ' '), Pixel(5, 1, ' '), Pixel(6, 1, ' '), Pixel(7, 1, ' '), Pixel(8, 1, ' '), Pixel(9, 1, ','),
        Pixel(2, 2, '.'), Pixel(3, 2, ' '), Pixel(4, 2, ' '), Pixel(5, 2, ' '), Pixel(6, 2, ' '), Pixel(7, 2, ' '), Pixel(8, 2, ' '), Pixel(9, 2, ' '), Pixel(10, 2, '.'),
        Pixel(1, 3, '/'), Pixel(2, 3, ' '), Pixel(3, 3, ' '), Pixel(4, 3, 'o'), Pixel(5, 3, ' '), Pixel(6, 3, ' '), Pixel(7, 3, ' '), Pixel(8, 3, 'o'), Pixel(9, 3, ' '), Pixel(10, 3, ' '), Pixel(11, 3, '\\'),
        Pixel(0, 4, '|'), Pixel(1, 4, ' '), Pixel(2, 4, ' '), Pixel(3, 4, ','), Pixel(4, 4, ' '), Pixel(5, 4, ' '), Pixel(6, 4, ' '), Pixel(7, 4, ' '), Pixel(8, 4, ' '), Pixel(9, 4, ','), Pixel(10, 4, ' '), Pixel(11, 4, ' '), Pixel(12, 4, '|'),
        Pixel(0, 5, '|'), Pixel(1, 5, ' '), Pixel(2, 5, ' '), Pixel(3, 5, ' '), Pixel(4, 5, '.'), Pixel(5, 5, '_'), Pixel(6, 5, '_'), Pixel(7, 5, '_'), Pixel(8, 5, '.'), Pixel(9, 5, ' '), Pixel(10, 5, ' '), Pixel(11, 5, ' '), Pixel(12, 5, '|'),
        Pixel(1, 6, '\\'), Pixel(2, 6, ' '), Pixel(3, 6, ' '), Pixel(4, 6, ','), Pixel(5, 6, '_'), Pixel(6, 6, '_'), Pixel(7, 6, '_'), Pixel(8, 6, ','), Pixel(9, 6, ' '), Pixel(10, 6, ' '), Pixel(11, 6, '/'),
        Pixel(2, 7, ','), Pixel(3, 7, ' '), Pixel(4, 7, ' '), Pixel(5, 7, ' '), Pixel(6, 7, ' '), Pixel(7, 7, ' '), Pixel(8, 7, ' '), Pixel(9, 7, ' '), Pixel(10, 7, ','),
        Pixel(3, 8, '.'), Pixel(4, 8, '_'), Pixel(5, 8, '_'), Pixel(6, 8, '_'), Pixel(7, 8, '_'), Pixel(8, 8, '_'), Pixel(9, 8, '.'),
    }}));
    setBounds(Point{12,8});
    setVelocity(Point{1,1});
    setCollisionLayer(0b0000000000000100);
	setCollisionMask(0b0000000000000001);
	heal(20);
}

void Boss::process(Game &game) {
}

void Boss::collideX(Entity *other) {
	if (auto p = dynamic_cast<Player*>(other)) {
        p->damage();
        p->doPush(getVelocity()*3);
    }	
}

void Boss::collideY(Entity *other) { 
	if (auto p = dynamic_cast<Player*>(other)) {
        p->damage();
        p->doPush(getVelocity()*3);
    }	
}

void Boss::collide(Border b) {
    if (b == Border::Top || b == Border::BOTTOM) reflectVelocityY();
    else reflectVelocityX();
}

void Boss::pass(Entity *other) { }
