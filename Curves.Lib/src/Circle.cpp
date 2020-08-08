#include "Circle.h"

Circle::Circle(double r, Vec3d c) : radius(r)
{
    if (r < 0)
        throw "radius must be possitive";
    _name = "Circle";
    center = c;
}

Vec3d Circle::get_fst_derivative(double t) const
{
    double x = -radius * sin(t);
    double y = radius * cos(t);

    return Vec3d{ x, y, 0 };
}

Vec3d Circle::get_point(double t) const
{
    double x = center.x + radius * cos(t);
    double y = center.y + radius * sin(t);
    double z = center.z;

    return Vec3d{ x, y, z };
}

double Circle::get_radius() const
{
    return radius;
}
