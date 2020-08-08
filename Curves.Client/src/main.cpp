#include "Curves.h"
#include <iostream>
#include <vector>
#include <memory>
#include <random>

using namespace std;

using curvePtr = shared_ptr<Curve>;

vector<curvePtr> gen_curves_vector()
{
	double max_radius = 50;
	double max_step = 10;

	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> radius_distr(0, max_radius);
	uniform_real_distribution<> step_distr(0, max_step);

	int curves_cnt = 10;
	int circle_cnt = 0,
		ellipse_cnt = 0,
		helix_cnt = 0;

	auto is_each_generated = [&]() { return circle_cnt * ellipse_cnt * helix_cnt != 0; };
	auto is_all_generated = [&]() { return circle_cnt + ellipse_cnt + helix_cnt >= curves_cnt; };

	vector<curvePtr> curves;
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

	return curves;
}

int main(int argc, char* argv[])
{
	vector<curvePtr> curves = gen_curves_vector();
	
	double t = 3.14 / 4;
	for (auto curve : curves)
		cout << curve->name() << ": " << curve->get_point(t) << endl;


	return 0;
}