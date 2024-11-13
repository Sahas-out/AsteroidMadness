#include"Coordinate.hpp"

Coordinate::Coordinate(double inX, double inY)
: x(inX),y(inY) {}
Coordinate::Coordinate(const Coordinate& other)
: x(other.x),y(other.y) {}
Coordinate& Coordinate::calcLineCoord(double directionAngle,double speed)
{
    return *(new Coordinate(this->x + speed*cos(directionAngle),this->y + speed*sin(directionAngle)));
}