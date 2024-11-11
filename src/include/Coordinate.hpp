#include <cmath>
class Coordinate
{
    public:
        double x;
        double y;
        Coordinate(double inX, double inY);
        Coordinate(const Coordinate& other);
        Coordinate& calcLineCoord(double directionAngle,double speed);
};