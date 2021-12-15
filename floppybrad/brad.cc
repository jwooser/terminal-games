#include "player.h"
#include <string>
#include <memory>
#include "projectile.h"
#include "animatedSprite.h"


void Brad::initialize(Game &game) {
    addSprite(std::make_unique<AnimatedSprite>(vector<Bitmap>{
        Bitmap{vector<Pixel>{
            Pixel(0,0,'\\'), Pixel(1,0,'('), Pixel(2,0,'o'), Pixel(3,0,'_'), Pixel(4,0,'o'), Pixel(5,0,')'), Pixel(6,0,'/')
        }},
        Bitmap{vector<Pixel>{
            Pixel(0,0,'/'), Pixel(1,0,'('), Pixel(2,0,'o'), Pixel(3,0,'_'), Pixel(4,0,'o'), Pixel(5,0,')'), Pixel(6,0,'\\')
        }}
    ));
    setBounds(Point{1,7});
    setCollisionLayer(0b0000000000000001);
    setAction(Action::UP, Point{0, -3});
    setGravitation(Border::BOTTOM);
}

void Brad::process(Game &game) { }

void Player::collideX(Entity *other) { }

void Player::collideY(Entity *other) { }

void Player::collide(Border b) { }

void Player::pass(Entity *other) { }

