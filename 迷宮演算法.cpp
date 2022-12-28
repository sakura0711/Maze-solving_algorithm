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

	void CreateMaze2D() {
		ptrMaze = new int* [size];
		for (int i = 0; i < size; i++) {
			ptrMaze[i] = new int[size];
		}
	}

	void ProduceRandomMaze() {
		for (int i = 0; i < size; i++) {
			ptrMaze[i][0] = 1;  // 開頭
			ptrMaze[i][size - 1] = 1;
			for (int j = 0; j < size; j++) {
				if (i == 0) { ptrMaze[0][j] = 1; } // 開頭
				if (i == size - 1) { ptrMaze[size - 1][j] = 1; } //結尾
				if (ptrMaze[i][j] != 1) { ptrMaze[i][j] = 0; }
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

	Maze maze;

	cin >> size;
	maze.Set_size(size);
	maze.CreateMaze2D();
	maze.ProduceRandomMaze();
	maze.PrintMaze();

}