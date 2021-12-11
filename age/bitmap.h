#ifndef BITMAP_H
#define BITMAP_H

#include <vector>
#include "point.h"

using std::vector;

struct Pixel {
    Point p;
    char c;

    Pixel(int x, int y, char c);
};

class Bitmap {
    vector<Pixel> theBitmap;

  public:
    Bitmap();
    Bitmap(char c);
    Bitmap(int width, int height, char c);
    Bitmap(vector<Pixel> pixels);
    const vector<Pixel>& get() const;
};

#endif
