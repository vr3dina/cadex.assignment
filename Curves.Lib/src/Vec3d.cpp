#include "Vec3d.h"

std::ostream& operator<<(std::ostream& out, const Vec3d& p)
{
	out << "{ " << p.x << ", " << p.y << ", " << p.z << " }";
	return out;
}

Vec3d::Vec3d(double x, double y, double z) : x(x), y(y), z(z)
{
}
