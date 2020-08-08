#pragma once
#include <ostream>

struct Vec3d
{
	Vec3d(double x, double y, double z);
	double x, y, z;
};

std::ostream& operator << (std::ostream& out, const Vec3d& p);
