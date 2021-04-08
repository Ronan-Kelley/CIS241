#include "circleLib.h"

const double cl_PI = 3.14159;

double calcPerim(double radius) {
	return radius * 2 * cl_PI;
}

double calcArea(double radius) {
	return radius * radius * cl_PI;
}
