#include "Polygon.hpp"

#include "Vector2D.hpp"
#include <iostream>
#include <cmath>
#include <vector>

Polygon::Polygon(std::initializer_list<Vec2> vertices_) {

    angle = 0;

    for (const Vec2& vertex : vertices_) {

        vertices.push_back(vertex);

    }

}

std::vector<Vec2> Polygon::edges() const {

    std::vector<Vec2> edges;
    for (int index = 0; index < vertices.size(); index++) {

        Vec2 edge = vertices[(index + 1) % vertices.size()] - vertices[index];
        edges.push_back(edge);

    }

    return edges;

}

std::vector<Vec2> Polygon::axes() const {

    std::vector<Vec2> axes;
    for (const Vec2& edge : edges()) {

        Vec2 axis = edge.perp().normalize();
        axes.push_back(axis);

    }

    return axes;

}

std::pair<double, double> Polygon::project(const Vec2& axis) const {

    std::vector<double> projections; 

    double min = vertices[0].dot(axis);
    double max = vertices[0].dot(axis);

    for (const Vec2& vertex: vertices) {

        double dot = vertex.dot(axis);

        projections.push_back(dot);

        if (dot < min) {
            min = dot;
        } else if (dot > min) {
            max = dot;
        }

    }

    std::pair<double, double> minmax;

    minmax.first = min;
    minmax.second = max;

    return minmax;

}

bool Polygon::overlap(double minA, double maxA, double minB, double maxB) const {

    return !(maxA < minB || maxB < minA);

}

bool Polygon::collide(const Polygon& other) const {

    return collidePolygon(other);

}

bool Polygon::collidePolygon(const Polygon& other) const {

    std::vector<Vec2> axes;

    for (Vec2 axis: this->axes()) {
        axes.push_back(axis);
    }
    for (Vec2 axis: other.axes()) {
        axes.push_back(axis);
    }

    for (Vec2 axis : axes) {

        std::pair<double, double> minmaxa = project(axis);
        std::pair<double, double> minmaxb = project(axis);

        if !(overlap(minmaxa.first, minmaxa[1], minmaxb[0], minmaxb[1])) {

            return false;

        }

    }

    return true;

}
