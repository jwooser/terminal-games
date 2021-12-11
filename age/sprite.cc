#include "sprite.h"

const Bitmap& Sprite::getFrame() { return frame(); }

void Sprite::setOffset(Point o) { offset = o; }

Point Sprite::getOffset() const { return offset; }
