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

	int colourBuffer1 [3] {0};
	int colourBuffer2 [3] {0};
	int colourBuffer3 [3] {0};
	int colourBuffer4 [3] {0};
	
	class Face
	{
	private:
		
		array<int,9>colour{};
		
	public:
		Face();
		Face(int);
		Face(const Face&);
		void exportColour(int, int* );
		void exportColour(char, int* );
		void importColour(int, int*);
		void importColour(char, int*);
		void rotateFace();
		char getChar(int);
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
	void rotateCounter(void ());
	void rotateFront();
	void rotateBack();
	void rotateLeft();
	void rotateRight();
	void rotateUp();
	void rotateDown();
	
};

