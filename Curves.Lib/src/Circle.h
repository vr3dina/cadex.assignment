#pragma once
#include "Curve.h"


class Circle : public Curve
{
public:
	Circle(double r, Vec3d p = Vec3d(0, 0, 0));

	Vec3d get_fst_derivative(double t) const override;
	Vec3d get_point(double t) const override;

private:
	double radius;
};

