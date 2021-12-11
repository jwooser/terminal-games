#include "animatedSprite.h"
#include <utility>

AnimatedSprite::AnimatedSprite(vector<Bitmap> theSprite):
theSprite {std::move(theSprite)},
currFrame {0}
{ }

const Bitmap& AnimatedSprite::frame() { 
    size_t frame = currFrame;
    ++currFrame;
    if (currFrame >= theSprite.size()) currFrame = 0;
    return theSprite.at(frame); 
}
