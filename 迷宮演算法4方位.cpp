#include <iostream>
#include <cstdlib>
using namespace std;

class Maze {

public:
	int size;
	int probability;
	int** ptrMaze;
	
	Maze(int size, int probability) { 
		this->size = size;
		this->probability = probability;
		CreateMaze2D();
		ProduceRandomMaze();
		//PrintMaze();
	}

	// void Set_size(int size) { this->size = size; }
	// void Set_probability(int probability) {this->probability= probability;}

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

			for (int j = 0; j < size; j++) 
			{
				if (i == 0) { ptrMaze[0][j] = 1; }				 // Wall (Up)
				else if (i == size - 1) { ptrMaze[size - 1][j] = 1; } //Wall (Down)
				else
				{ 
					int randSeed = rand() % 10;
					if (randSeed < probability) { ptrMaze[i][j] = 1; }
					else { ptrMaze[i][j] = 0; }
				}
			}
		}

		ptrMaze[1][1] = 0;				 // START 
		ptrMaze[size - 2][size - 2] = 0; // END
	}

	void PrintMaze() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << ptrMaze[i][j] << " ";
			}
			cout << endl;
		}
	}

	int VistMaze(int i, int j)
	{
		int end = 0;

		//假設能夠走通
		ptrMaze[i][j] = 2;

		//如果到達重點則將end置為0表示迷宮已經走結束
		if (i == size - 2  && j == size - 2) {
			end = 1;
		}
		//如果迷宮沒有走結束則將搜尋所在位置的右、下、左、上四個方向是否能夠走通
		if (end != 1 && j + 1 <= size - 1 && ptrMaze[i][j + 1] == 0) {		//右
			if (VistMaze(i, j + 1) == 1)
				return 1;
		}
		if (end != 1 && i + 1 <= size - 1 && ptrMaze[i + 1][j] == 0) {		//下
			if (VistMaze(i + 1, j) == 1)
				return 1;
		}
		if (end != 1 && j - 1 >= 1 && ptrMaze[i][j - 1] == 0) {	//左
			if (VistMaze(i, j - 1) == 1)
				return 1;
		}
		if (end != 1 && i - 1 >= 1 && ptrMaze[i - 1][j] == 0) {	//上
			if (VistMaze(i - 1, j) == 1)
				return 1;
		}	//當四周都不通的時候將其置回0
		if (end != 1) {
			ptrMaze[i][j] = 0;
		}

		return end;
	}

	void Delete() {
		for (int i = 0; i < size; i++)
		{
			delete[] ptrMaze[i];
		}
		delete[] ptrMaze;
	}
};

int main() 
{
	srand(time(NULL));
	int mazeSize[] = {10,20,30,40,50};
	int probability[] = { 10,20,40,60,80 };

	for (int i = 0; i < size(mazeSize); i++) {
		for (int j = 0; j < size(probability); j++) {
			Maze maze(mazeSize[i], probability[j]);
			maze.PrintMaze();
			cout << mazeSize[i] << "(" << 100 - probability[j] << "%)" << " : " << maze.VistMaze(1, 1) << endl;
			maze.Delete();
		}
	}

}