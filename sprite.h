#ifndef SPRITE_H
#define SPRITE_H

#include "bitmap.h"
#include "point.h"

class Sprite {
    Point offset;

    virtual const Bitmap& frame() = 0;
  public:
	  virtual ~Sprite() = default;
    const Bitmap& getFrame();
    void setOffset(Point o);
    Point getOffset() const;

};

#endif
