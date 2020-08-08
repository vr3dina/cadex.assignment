#pragma once
#include "Curves.h"
#include <memory>
#include <vector>

using curvePtr = std::shared_ptr<Curve>;
using circlePtr = std::shared_ptr<Circle>;

class CurvresManager
{
public:
	void generate_curves(int cnt, double max_radius, double max_step);
	void print(double t = M_PI_4) const;
	void print_circles() const;
	
	const std::vector<circlePtr>& get_circles();
	const std::vector<circlePtr>& extract_circles();
	void sort_circles();

private:
	std::vector<curvePtr> curves;
	std::vector<circlePtr> circles;
};

