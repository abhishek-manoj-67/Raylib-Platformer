#include <iostream>

class Vec2 {
public:
    // methods
    Vec2() : x(0), y(0) {};
    Vec2(double x_, double y_) : x(x_), y(y_) {};

    double magnitude() const;
    double magnitudeSquared() const;
    double angle() const;

    double dot(const Vec2& other) const;
    double cross(const Vec2& other) const;

    Vec2 normalize() const;
    Vec2 perp() const;

    // attrs
    double x, y;

protected:


private:

};
