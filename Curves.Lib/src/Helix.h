#pragma once
#include "Curve.h"

class Helix : public Curve
{
public:
	Helix(double r, double s, Vec3d c = Vec3d(0, 0 ,0));

	Vec3d get_fst_derivative(double t) const override;
	Vec3d get_point(double t) const override;

private:
	double radius;
	double step;
};

