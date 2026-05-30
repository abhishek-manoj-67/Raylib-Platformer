#pragma once

#include "Vector2D.hpp"
#include <iostream>
#include <cmath>
#include <vector>

// github repo test

class Polygon {
public:
    // Constructor
    Polygon() {};
    Polygon(std::initializer_list<Vec2> vertices_);

    
    // methods
    std::vector<Vec2> edges() const;
    std::vector<Vec2> axes() const;
    std::pair<double, double> project(const Vec2& axis) const;
    bool overlap(double minA, double maxA, double minB, double maxB) const;
    bool collide(const Polygon& other) const;

    // attrs
    std::vector<Vec2> vertices;
    double angle;

protected:

private:
    bool collidePolygon(const Polygon& other) const;

};
