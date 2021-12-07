#include "point.h"

Point::Point():
x {0},
y {0}
{ }

Point::Point(int x, int y):
x {x},
y {y}
{ }

Point &Point::operator+=(const Point &other) {
    x += other.x;
    y += other.y;
    return *this;
}

Point &Point::operator-=(const Point &other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

const Point Point::operator+(const Point &other) const {
    Point result = *this;
    result += other;
    return result;
}

const Point Point::operator-(const Point &other) const {
    Point result = *this;
    result -= other;
    return result;
}

Point &Point::operator*=(const int n) {
    x *= n;
    y *= n;
    return *this;
}

const Point Point::operator*(const int n) const {
    Point result = *this;
    result *= n;
    return result;
}

const Point operator*(const int n, const Point &p) {
	Point result = p;
	result *= n;
	return result;
}
