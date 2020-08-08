#include "Curves.h"
#include "CurvresManager.h"
#include <iostream>
#include <vector>
#include <memory>
#include <random>

using namespace std;


int main(int argc, char* argv[])
{
	CurvresManager cm;
	cm.generate_curves(10, 20, 5);
	cm.print();


	auto v = cm.extract_circles();
	cout << "\nRadii of extracted circles: " << endl;
	cm.print_circles();

	cm.sort_circles();
	cout << "\n\nSorted radii of circles: " << endl;
	cm.print_circles();

	cout << endl << endl;
	return 0;
}