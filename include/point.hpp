#ifndef POINT_HPP
#define POINT_HPP

struct Point {
    int x, y;

    Point() : x(0), y(0) {}
    Point(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Point& other) const {
        return !(*this == other);
    }
};

#endif // POINT_HPP
