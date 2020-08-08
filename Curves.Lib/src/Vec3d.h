#pragma once
#include <ostream>
#include <string>

struct Vec3d
{
	Vec3d(double x, double y, double z);
	std::string to_string() const;
	double x, y, z;
};

std::ostream& operator << (std::ostream& out, const Vec3d& p);
