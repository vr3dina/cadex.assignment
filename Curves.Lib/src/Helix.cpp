#include "Helix.h"

Helix::Helix(double r, double s, Vec3d c) : radius(r), step(s)
{
    if (r < 0)
        throw "radii must be possitive";
    _name = "Helix";
    center = c;
}

Vec3d Helix::get_fst_derivative(double t) const
{
    double x = -radius * sin(t);
    double y = radius * cos(t);
    double z = step / (2. * M_PI);

    return Vec3d{ x, y, z };
}

Vec3d Helix::get_point(double t) const
{
    double x = center.x + radius * cos(t);
    double y = center.y + radius * sin(t);
    double z = center.z + step * t / (2. * M_PI);
    
    return Vec3d{ x, y, z };
}
