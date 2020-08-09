#include "Curves.h"
#include "CurvresManager.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	CurvresManager cm;
	cm.generate_curves(/*count*/10, /*max radius*/ 20, /*max step*/ 5);
	cm.print();

	cm.extract_circles();
	cout << "\nRadii of extracted circles: " << endl;
	cm.print_circles();

	cm.sort_circles();
	cout << "\n\nSorted circles by radii: " << endl;
	cm.print_circles();

	cout << "\n\nSum of circles radii: " << cm.sum_of_circle_radii();

	cout << endl << endl;
	return 0;
}