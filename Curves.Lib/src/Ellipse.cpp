#include "Ellipse.h"

Ellipse::Ellipse(double rX, double rY, Vec3d c) : radiusX(rX), radiusY(rY)
{
    if (rX < 0 || rY < 0)
        throw "radii must be possitive";
    _name = "Ellipse";
    center = c;
}

Vec3d Ellipse::get_fst_derivative(double t) const
{
    double x = -radiusX * sin(t);
    double y = radiusY * cos(t);
    
    return Vec3d{ x, y, 0 };
}

Vec3d Ellipse::get_point(double t) const
{
    double x = center.x + radiusX * cos(t);
    double y = center.y + radiusY * sin(t);
    double z = center.z;
    
    return Vec3d{ x, y, z };
}

