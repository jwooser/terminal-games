#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <vector>
#include "sprite.h"
#include "bitmap.h"

class AnimatedSprite : public Sprite {
    vector<Bitmap> theSprite;
    size_t currFrame;

    const Bitmap& frame() override;
  public:
    AnimatedSprite(vector<Bitmap> theSprite);
};


#endif
