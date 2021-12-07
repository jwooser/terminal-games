#include "staticSprite.h"
#include <utility>

StaticSprite::StaticSprite(Bitmap theSprite):
theSprite {std::move(theSprite)}
{ }

const Bitmap& StaticSprite::frame() { return theSprite; }
