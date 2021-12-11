#include "bitmap.h"
#include <utility>

Pixel::Pixel(int x, int y, char c):
p {Point{x, y}},
c {c}
{ }

Bitmap::Bitmap() { }

Bitmap::Bitmap(char c) {
    theBitmap.push_back(Pixel{0, 0, c});
}

Bitmap::Bitmap(int width, int height, char c) {
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            theBitmap.push_back(Pixel{x, y, c});
        }
    }
}

Bitmap::Bitmap(vector<Pixel> pixels):
theBitmap {std::move(pixels)}
{ }

const vector<Pixel>& Bitmap::get() const { return theBitmap; }
