#include <iomanip>
#include <iostream>
#include "Cube.h"
using namespace std;

void printCube(int);

int main()
{
	Cube a;
	a.printCubeState();
	a.rotateBack();
	a.rotateFront();
	a.printCubeState();
}


