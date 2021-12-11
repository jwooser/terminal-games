#include "player.h"
#include <string>
#include <memory>
#include "projectile.h"
#include "staticSprite.h"

const std::vector<Point> Player::bulletDirection = {
    Point{0,-1},
    Point{0,1},
    Point{-1,0},
    Point{1,0}
};

void Player::initialize(Game &game) {
    addSprite(std::make_unique<StaticSprite>(Bitmap{'p'}));
    setBounds(Point{1,1});
    setCollisionLayer(0b0000000000000001);
    setAction(Action::UP, Point{0, -1});
    setAction(Action::DOWN, Point{0, 1});
    setAction(Action::LEFT, Point{-1, 0});
    setAction(Action::RIGHT, Point{1, 0});
	heal(5);
	game.updateStatus(2, "Health: " + std::to_string(gethp()));
}

void Player::shoot(size_t dir) {
    Projectile *p = queueSpawn(std::make_unique<Projectile>());
    p->setPosition(getPosition() + bulletDirection[dir]);
    p->setVelocity(bulletDirection[dir] * 2);
	cooldown = 1;
}

void Player::process(Game &game) {
    if (cooldown == 0) {
        if(game.getInput() == Action::ALT_UP) shoot(0);
        else if(game.getInput() == Action::ALT_DOWN) shoot(1);
        else if(game.getInput() == Action::ALT_LEFT) shoot(2);
        else if(game.getInput() == Action::ALT_RIGHT) shoot(3);
    } else --cooldown;
	game.updateStatus(2, "Health: " + std::to_string(gethp()));
}

void Player::collideX(Entity *other) { }

void Player::collideY(Entity *other) { }

void Player::collideB(Border b) { }

void Player::passEntity(Entity *other) { }
