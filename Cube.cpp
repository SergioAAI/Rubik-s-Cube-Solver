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
			colour[i*3 +j] = 0;
		}
	}
}

Cube::Face::Face(int colour1)
{
	for(int i = 0; i<3;i++)
	{
		for(int j = 0; j<3;j++)
		{
			colour[i*3 +j] = colour1;
		}
	}
}

Cube::Face::Face(const Face& a)
{
	for(int i = 0; i<3;i++)
	{
		for(int j = 0; j<3;j++)
		{
			colour[i*3+j] = a.colour[i*3+j];
		}
	}
}

void Cube::Face::exportColour(int row, int *array1)
{
	for (int i = 0; i<3;i++)
	{
		array1[i] = colour[3*(row-1) + i];
	}

		
}

void Cube::Face::exportColour(char column, int *array1)
{
	int columnNumb = column - 65; //From ASCII to a number
	for (int i = 0; i<3;i++)
	{
		array1[i] = colour[3*i + columnNumb];
	}
}

void Cube::Face::importColour(int row, int *array1)
{
	for (int i = 0; i<3;i++)
	{
		colour[3*(row-1) + i] = array1[i];
	}

}

void Cube::Face::importColour(char column, int *array1)
{
		int columnNumb = column - 65; //From ASCII to a number
	for (int i = 0; i<3;i++)
	{
		colour[3*i + columnNumb] = array1[i];
	}
}

void Cube::Face::rotateFace()
{
	array<int,8> rotateBuffer{};
	for(int i = 0; i <8; i++)
	{
		if (i<5)
			rotateBuffer[i]= colour[i];
		else
			rotateBuffer[i]= colour[i+1];
	}

	for(int i = 0; i <3; i++)
	{
		for (int j = 0; j <3; j++)
		{
			if ((3*i +j) == 8 )
				break;
			
			if ((3*i+j)< 5)
				colour[3*j+(2-i)] = rotateBuffer[i*3+j];
			else
				colour[3*j+(2-i)] = rotateBuffer[(i*3+j)-1];
		}
	}

	
	
}

char Cube::Face::getChar(int number)
{
	switch (colour[number-1])
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
	cout << setw(14)<< "| " << this->up.getChar(1) <<"  " << this->up.getChar(2) <<"  " << this->up.getChar(3) <<" |" << endl;
	cout << setw(14)<< "| " << this->up.getChar(4) <<"  " << this->up.getChar(5) <<"  " << this->up.getChar(6) <<" |" << endl;
	cout << setw(14)<< "| " << this->up.getChar(7) <<"  " << this->up.getChar(8) <<"  " << this->up.getChar(9) <<" |" << endl;
	cout << setw(23)<< "-----------" << endl;

	//line 5
	cout << "-----------" << " ";
	cout << "-----------" << " ";
	cout << "-----------" << " ";
	cout << "-----------" << endl;

	// Line 6
	cout << "| " << this->left.getChar(1) <<"  " << this->left.getChar(2) <<"  " << this->left.getChar(3) <<" |" << " " ;
	cout << "| " << this->front.getChar(1) <<"  " << this->front.getChar(2) <<"  " << this->front.getChar(3) <<" |" << " " ;
	cout << "| " << this->right.getChar(1) <<"  " << this->right.getChar(2) <<"  " << this->right.getChar(3) <<" |" << " " ;
	cout << "| " << this->back.getChar(1) <<"  " << this->back.getChar(2) <<"  " << this->back.getChar(3) <<" |" << endl;

	// Line 7
	cout << "| " << this->left.getChar(4) <<"  " << this->left.getChar(5) <<"  " << this->left.getChar(6) <<" |" << " " ;
	cout << "| " << this->front.getChar(4) <<"  " << this->front.getChar(5) <<"  " << this->front.getChar(6) <<" |" << " " ;
	cout << "| " << this->right.getChar(4) <<"  " << this->right.getChar(5) <<"  " << this->right.getChar(6) <<" |" << " " ;
	cout << "| " << this->back.getChar(4) <<"  " << this->back.getChar(5) <<"  " << this->back.getChar(6) <<" |" << endl;

	// Line 8
	cout << "| " << this->left.getChar(7) <<"  " << this->left.getChar(8) <<"  " << this->left.getChar(9) <<" |" << " " ;
	cout << "| " << this->front.getChar(7) <<"  " << this->front.getChar(8) <<"  " << this->front.getChar(9) <<" |" << " " ;
	cout << "| " << this->right.getChar(7) <<"  " << this->right.getChar(8) <<"  " << this->right.getChar(9) <<" |" << " " ;
	cout << "| " << this->back.getChar(7) <<"  " << this->back.getChar(8) <<"  " << this->back.getChar(9) <<" |" << endl;

	// Line 9
	cout << "-----------" << " ";
	cout << "-----------" << " ";
	cout << "-----------" << " ";
	cout << "-----------" << endl;

	// Cube Face down
	cout << setw(23)<< "-----------" << endl;
	cout << setw(14)<< "| " << this->down.getChar(1) <<"  " << this->down.getChar(2) <<"  " << this->down.getChar(3) <<" |" << endl;
	cout << setw(14)<< "| " << this->down.getChar(4) <<"  " << this->down.getChar(5) <<"  " << this->down.getChar(6) <<" |" << endl;
	cout << setw(14)<< "| " << this->down.getChar(7) <<"  " << this->down.getChar(8) <<"  " << this->down.getChar(9) <<" |" << endl;
	cout << setw(23)<< "-----------" << endl;
}

void Cube::rotateCounter(void function1())
{
	for(int i =0; i<3 ; i++)
		function1();
}

void Cube::rotateFront()
{
	front.rotateFace();

	left.exportColour('C',colourBuffer1);
	up.exportColour(3,colourBuffer2);
	right.exportColour('A',colourBuffer3);
	down.exportColour(1,colourBuffer4);

	left.importColour('C',colourBuffer4);
	up.importColour(3,colourBuffer1);
	right.importColour('A',colourBuffer2);
	down.importColour(1,colourBuffer3);
}

void Cube::rotateBack()
{
	back.rotateFace();

	up.exportColour(1,colourBuffer1);
	left.exportColour('A',colourBuffer2);
	down.exportColour(3,colourBuffer3);
	right.exportColour('C',colourBuffer4);

	up.importColour(1,colourBuffer4);
	left.importColour('A',colourBuffer1);
	down.importColour(3,colourBuffer2);
	right.importColour('C',colourBuffer3);
}

void Cube::rotateLeft()
{
	left.rotateFace();

	up.exportColour('A',colourBuffer1);
	front.exportColour('A',colourBuffer2);
	down.exportColour('A',colourBuffer3);
	right.exportColour('C',colourBuffer4);

	up.importColour('A',colourBuffer4);
	front.importColour('A',colourBuffer1);
	down.importColour('A',colourBuffer2);
	right.importColour('C',colourBuffer3);
}

void Cube::rotateRight()
{
	right.rotateFace();

	up.exportColour('C',colourBuffer1);
	back.exportColour('A',colourBuffer2);
	down.exportColour('C',colourBuffer3);
	front.exportColour('C',colourBuffer4);

	up.importColour('C',colourBuffer4);
	back.importColour('A',colourBuffer1);
	down.importColour('C',colourBuffer2);
	front.importColour('C',colourBuffer3);
}

void Cube::rotateUp()
{
	up.rotateFace();

	left.exportColour(1,colourBuffer1);
	front.exportColour(1,colourBuffer2);
	right.exportColour(1,colourBuffer3);
	back.exportColour(1,colourBuffer4);

	left.importColour(1,colourBuffer4);
	front.importColour(1,colourBuffer1);
	right.importColour(1,colourBuffer2);
	back.importColour(1,colourBuffer3);
}

void Cube::rotateDown()
{
	down.rotateFace();

	left.exportColour(3,colourBuffer1);
	front.exportColour(3,colourBuffer2);
	right.exportColour(3,colourBuffer3);
	back.exportColour(3,colourBuffer4);

	left.importColour(3,colourBuffer4);
	front.importColour(3,colourBuffer1);
	right.importColour(3,colourBuffer2);
	back.importColour(3,colourBuffer3);
}
