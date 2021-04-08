#include <stdio.h>
#include "circleLib.h"
#include "newLib.h"

int main(int argc, char** argv) {
	printf("circle perimeter with radius of 3: %f\ncircle area with radius of 3: %f\n", calcPerim(3), calcArea(3));
	printf("rectangle perimeter with height of 3, length of 5: %f\nrectangle perimeter with height of 3, length of 5: %f\n", calcRecPerim(3, 5), calcRecPerim(3, 5));
}
