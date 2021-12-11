#ifndef POINT_H
#define POINT_H

struct Point {
    int x, y;
	
	Point();
    Point(int x, int y);
    Point &operator+=(const Point &other);
    Point &operator-=(const Point &other);
    const Point operator+(const Point &other) const;
    const Point operator-(const Point &other) const;
    Point &operator*=(const int n);
    const Point operator*(const int n) const;
};

const Point operator*(const int n, const Point &p);

#endif
