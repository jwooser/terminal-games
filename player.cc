#include "player.h"
#include <memory>
#include "projectile.h"

const vector<Point> bulletDirection = {
    Point{0,-1},
    Point{0,1},
    Point{-1,0},
    Point{1,0}
}

void Player::initialize(Game &game) {
    addSprite(std::make_unique<StaticSprite>(Bitmap{'p'}));
    setBounds(Point{1,1});
    setCollisionLayer(0b0000000000000001);
    setAction(Action::UP, Point{0, -1});
    setAction(Action::DOWN, Point{0, 1});
    setAction(Action::LEFT, Point{-1, 0});
    setAction(Action::RIGHT, Point{1, 0});
}

void shoot(size_t dir) {
    Projectile *p = queueSpawn(std::make_unique<Projectile>());
    p->setPosition(getPosition() + bulletDirection[dir]);
    p->setVelocity(bulletDirection[dir] * 2);
}
void Player::process(Game &game) {
    if (cooldown == 0) {
        cooldown = 1;
        if(game.getInput() == Action::ALT_UP) direction = 0;
        else if(game.getInput() == Action::ALT_DOWN) direction = 1;
        else if(game.getInput() == Action::ALT_LEFT) direction = 2;
        else if(game.getInput() == Action::ALT_RIGHT) direction = 3;
    } else --cooldown;
}

void Player::collideX(Entity *other) { }

void Player::collideY(Entity *other) { }

void Player::collideB(Border b) { }

void Player::passEntity(Entity *other) { }
