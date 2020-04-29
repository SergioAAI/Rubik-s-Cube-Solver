#pragma once
#include <array>
#define white 1
#define green 2
#define red 3
#define blue 4
#define orange 5
#define yellow 6
using namespace std;

class Cube
{
private:

	class Face
	{
	private:
		int colour[3][3];
		
	public:
		Face();
		Face(int);
		Face(const Face&);
		void receiveColour();
		void rotateFace();
		char getchar(int);
	};

	Face up;
	Face left;
	Face front;
	Face right;
	Face back;
	Face down;

public:

	Cube();
	void printCubeState();
	void rotateCounter(int);
	void rotateFront();
	void rotateBack();
	void rotateLeft();
	void rotateRight();
	void rotateUp();
	void rotateDown();
	
};

