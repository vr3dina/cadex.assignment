#include "CurvresManager.h"
#include <random>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <memory>
#include <numeric>

using namespace std;

void CurvresManager::generate_curves(int curves_cnt, double max_radius, double max_step)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> radius_distr(0, max_radius);
	uniform_real_distribution<> step_distr(0, max_step);

	int circle_cnt = 0,
		ellipse_cnt = 0,
		helix_cnt = 0;

	auto is_each_generated = [&]() { return circle_cnt * ellipse_cnt * helix_cnt != 0; };
	auto is_all_generated = [&]() { return circle_cnt + ellipse_cnt + helix_cnt >= curves_cnt; };

	srand(time(NULL));
	curves.reserve(curves_cnt);
	do
	{
		int curve_type = rand() % 3;
		switch (curve_type)
		{
		case 0:
			curves.push_back(make_shared<Circle>(radius_distr(gen)));
			circle_cnt++;
			break;
		case 1:
			curves.push_back(make_shared<Ellipse>(radius_distr(gen), radius_distr(gen)));
			ellipse_cnt++;
			break;
		case 2:
			curves.push_back(make_shared<Helix>(radius_distr(gen), step_distr(gen)));
			helix_cnt++;
			break;
		}
	} while (!is_each_generated() || !is_all_generated());
}

#define SW setw(35) <<
void CurvresManager::print(double t) const
{
	cout << "t = " << t << endl;
	cout << setw(10) << std::left << "curve" << SW "point" << SW "1st derivative" << SW endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	for (auto curve : curves)
		cout << setw(10) << curve->name()
		<< SW curve->get_point(t)
		<< SW curve->get_fst_derivative(t).to_string()
		<< SW endl;
}

void CurvresManager::print_circles() const
{
	for (auto circle : circles)
	{
		cout << circle->get_radius() << " ";
	}
}

const vector<circlePtr>& CurvresManager::get_circles()
{
	return circles;
}

const vector<circlePtr>& CurvresManager::extract_circles()
{
	for (const auto& curve : curves)
	{
		if (auto circle = dynamic_pointer_cast<Circle>(curve))
		{
			circles.push_back(circle);
		}
	}
	return circles;

	//copy_if(curves.begin(), curves.end(), back_inserter(circles),
	//	[](curvePtr curve)
	//	{
	//		return dynamic_pointer_cast<Circle>(curve) != nullptr;
	//	});
}

void CurvresManager::sort_circles()
{
	sort(circles.begin(), circles.end(),
		[](circlePtr lhs, circlePtr rhs) { return lhs->get_radius() < rhs->get_radius(); });
}

double CurvresManager::sum_of_circle_radii() const
{
	return accumulate(circles.begin(), circles.end(), 0., 
		[](double init, circlePtr crc) { return init + crc->get_radius(); });
}
