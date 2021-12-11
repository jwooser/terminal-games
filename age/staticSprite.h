#ifndef STATICSPRITE_H
#define STATICSPRITE_H

#include "sprite.h"
#include "bitmap.h"

class StaticSprite : public Sprite {
    Bitmap theSprite;

    const Bitmap& frame() override;
  public:
    StaticSprite(Bitmap theSprite);
};

#endif
