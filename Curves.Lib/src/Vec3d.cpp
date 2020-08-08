#include "Vec3d.h"
#include <sstream>

std::ostream& operator<<(std::ostream& out, const Vec3d& p)
{
	out << p.to_string();
	return out;
}

Vec3d::Vec3d(double x, double y, double z) : x(x), y(y), z(z)
{
}

std::string Vec3d::to_string() const
{
	std::stringstream ss;
	ss << "{ " << x << ", " << y << ", " << z << " }";
	return ss.str();
}
