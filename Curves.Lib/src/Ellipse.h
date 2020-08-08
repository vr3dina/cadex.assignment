#pragma once
#include "Curve.h"

class Ellipse : public Curve
{
public:
	Ellipse(double rX, double rY, Vec3d c = Vec3d(0, 0, 0 ));

	Vec3d get_fst_derivative(double t) const override;
	Vec3d get_point(double t) const override;

private:
	double radiusX;
	double radiusY;
};

