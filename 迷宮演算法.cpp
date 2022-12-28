#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct {

}Road;

class Maze {

public:
	Road* road;
	int size;
	int probability;
	int** ptrMaze;
	
	void Set_size(int size) { this->size = size; }
	void Set_probability(int probability) {this->probability= probability;}

	void CreateMaze2D() {
		ptrMaze = new int* [size];
		for (int i = 0; i < size; i++) {
			ptrMaze[i] = new int[size];
		}
	}

	void ProduceRandomMaze() {

		probability = probability / 10;

		for (int i = 0; i < size; i++) 
		{
			ptrMaze[i][0] = 1;				 // Wall (Left)
			ptrMaze[i][size - 1] = 1;		 // Wall (Right)
			ptrMaze[1][1] = 8;				 // START 
			ptrMaze[size - 2][size - 2] = 8; // END

			for (int j = 0; j < size; j++) 
			{
				int randSeed = rand() % 10;
				if (i == 0) { ptrMaze[0][j] = 1; }				 // Wall (Up)
				if (i == size - 1) { ptrMaze[size - 1][j] = 1; } //Wall (Down)
				if (ptrMaze[i][j] != 1) 
				{ 
					if (randSeed < probability) { ptrMaze[i][j] = 1; }
					else { ptrMaze[i][j] = 0; }
				}
			}
		}
	}

	void PrintMaze() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << ptrMaze[i][j] << " ";
			}
			cout << endl;
		}
	}


};

int main() 
{
	srand(time(NULL));
	int size;
	int probability;
	Maze maze;

	cin >> size >> probability;
	maze.Set_size(size);
	maze.Set_probability(probability);
	maze.CreateMaze2D();
	maze.ProduceRandomMaze();
	maze.PrintMaze();

}