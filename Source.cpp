#include <iomanip>
#include <iostream>
#include "Cube.h"
using namespace std;

void printCube(int);

int main()
{
	Cube a;
	a.printCubeState();
}

void printCube(const int space)
{

	cout << setw(23)<< "-----------" << endl;
	cout << setw(23)<< "|    b  b |" << endl;
	cout << setw(23)<< "| r  r  r |" << endl;
	cout << setw(23)<< "| r  r  r |" << endl;
	cout << setw(23)<< "-----------" << endl;

	cout << "-----------" << " " << "-----------"<< " " << "-----------"<< " " << "-----------" << endl;
	cout << "| b  b  b |" << " " << "-----------"<< " " << "-----------"<< " " << "-----------" << endl;
	cout << "| r  r  r |" << " " << "-----------"<< " " << "-----------"<< " " << "-----------" << endl;
	cout << "| r  r  r |" << " " << "-----------"<< " " << "-----------"<< " " << "-----------" << endl;
	cout << "-----------" << " " << "-----------"<< " " << "-----------"<< " " << "-----------" << endl;

	cout << setw(23)<< "-----------" << endl;
	cout << setw(23)<< "| b  b  b |" << endl;
	cout << setw(23)<< "| r  r  r |" << endl;
	cout << setw(23)<< "| r  r  r |" << endl;
	cout << setw(23)<< "-----------" << endl;
}
