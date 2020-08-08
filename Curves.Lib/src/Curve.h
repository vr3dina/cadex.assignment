#pragma once
#define _USE_MATH_DEFINES
#include "Vec3d.h"
#include <math.h>
#include <string>

class Curve
{
public:
	virtual Vec3d get_point(double t) const = 0;
	virtual Vec3d get_fst_derivative(double t) const = 0;
	std::string name() const;

protected:
	std::string _name;
	Vec3d center = Vec3d(0,0,0);
};
