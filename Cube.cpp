#include "Cube.h"
#include "iostream"
#include "iomanip"

#define white 1
#define green 2
#define red 3
#define blue 4
#define orange 5
#define yellow 6

using namespace std;
Cube::Face::Face()
{
	
	for(int i = 0; i<3;i++)
	{
		for(int j = 0; j<3;j++)
		{
			colour[i][j] = 0;
		}
	}
}

Cube::Face::Face(int colour1)
{
	for(int i = 0; i<3;i++)
	{
		for(int j = 0; j<3;j++)
		{
			colour[i][j] = colour1;
		}
	}
}

Cube::Face::Face(const Face& A)
{
	for(int i = 0; i<3;i++)
	{
		for(int j = 0; j<3;j++)
		{
			colour[i][j] = A.colour[i][j];
		}
	}
}

char Cube::Face::getchar(int number)
{
	int position[9];
	for(int i = 0; i<3;i++)
	{
		for(int j = 0; j<3;j++)
		{
			position[i*3+j] = colour[i][j];
		}
	}

	switch (position[number-1])
	{
	case white:
		{
			return 'w';
		}
	case green:
		{
			return 'g';
		}
	case red:
		{
			return 'r';
		}
	case blue:
		{
			return 'b';
		}
	case orange:
		{
			return 'o';
		}
	case yellow:
		{
			return 'y';
		}
	default:
		{
			return ' ';
		};
	}
}

Cube::Cube()
{
	up = Face (white);
	left = Face (green);
	front = Face (red);
	right = Face (blue);
	back = Face (orange);
	down = Face (yellow);
	
}

void Cube::printCubeState()
{
	// Cube Face Up
	cout << setw(23)<< "-----------" << endl;
	cout << setw(14)<< "| " << this->up.getchar(1) <<"  " << this->up.getchar(2) <<"  " << this->up.getchar(3) <<" |" << endl;
	cout << setw(14)<< "| " << this->up.getchar(4) <<"  " << this->up.getchar(5) <<"  " << this->up.getchar(6) <<" |" << endl;
	cout << setw(14)<< "| " << this->up.getchar(7) <<"  " << this->up.getchar(8) <<"  " << this->up.getchar(9) <<" |" << endl;
	cout << setw(23)<< "-----------" << endl;

	//line 5
	cout << "-----------" << " ";
	cout << "-----------" << " ";
	cout << "-----------" << " ";
	cout << "-----------" << endl;

	// Line
	cout << "| " << this->left.getchar(1) <<"  " << this->left.getchar(2) <<"  " << this->left.getchar(3) <<" |" << " " ;
	cout << "| " << this->front.getchar(1) <<"  " << this->front.getchar(2) <<"  " << this->front.getchar(3) <<" |" << " " ;
	cout << "| " << this->right.getchar(1) <<"  " << this->right.getchar(2) <<"  " << this->right.getchar(3) <<" |" << " " ;
	cout << "| " << this->back.getchar(1) <<"  " << this->back.getchar(2) <<"  " << this->back.getchar(3) <<" |" << endl;
	
	cout << "| " << this->left.getchar(4) <<"  " << this->left.getchar(5) <<"  " << this->left.getchar(6) <<" |" << " " ;
	cout << "| " << this->front.getchar(4) <<"  " << this->front.getchar(5) <<"  " << this->front.getchar(6) <<" |" << " " ;
	cout << "| " << this->right.getchar(4) <<"  " << this->right.getchar(5) <<"  " << this->right.getchar(6) <<" |" << " " ;
	cout << "| " << this->back.getchar(4) <<"  " << this->back.getchar(5) <<"  " << this->back.getchar(6) <<" |" << endl;
	
	cout << "| " << this->left.getchar(7) <<"  " << this->left.getchar(8) <<"  " << this->left.getchar(9) <<" |" << " " ;
	cout << "| " << this->front.getchar(7) <<"  " << this->front.getchar(8) <<"  " << this->front.getchar(9) <<" |" << " " ;
	cout << "| " << this->right.getchar(7) <<"  " << this->right.getchar(8) <<"  " << this->right.getchar(9) <<" |" << " " ;
	cout << "| " << this->back.getchar(7) <<"  " << this->back.getchar(8) <<"  " << this->back.getchar(9) <<" |" << endl;
	
	cout << "-----------" << " ";
	cout << "-----------" << " ";
	cout << "-----------" << " ";
	cout << "-----------" << endl;
	
	cout << setw(23)<< "-----------" << endl;
	cout << setw(14)<< "| " << this->down.getchar(1) <<"  " << this->down.getchar(2) <<"  " << this->down.getchar(3) <<" |" << endl;
	cout << setw(14)<< "| " << this->down.getchar(4) <<"  " << this->down.getchar(5) <<"  " << this->down.getchar(6) <<" |" << endl;
	cout << setw(14)<< "| " << this->down.getchar(7) <<"  " << this->down.getchar(8) <<"  " << this->down.getchar(9) <<" |" << endl;
	cout << setw(23)<< "-----------" << endl;
}
