#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include "block.h"
using namespace std;

const unsigned int numberOfMines = 10;
const unsigned int tableSize = 9;
Block gameBoard[tableSize][tableSize];

void plantMines(Block, const int);
void printTable(Block[][tableSize]);
void initializeTable(Block[][tableSize]);
int main()
{
	initializeTable(gameBoard);
	printTable(gameBoard);
	return 0;
}
void initializeTable(Block board[][tableSize])
{
	for (int i = 0; i < tableSize; i++)
	{
		for (int j = 0; j < tableSize; j++)
		{
			board[i][j].setNumber(0);
		}
	}
}

void plantMines(Block board[][tableSize], const int size)
{
	srand(static_cast<unsigned int>(time(0)));

	//initialize elements in gameBoard.

	//plant mines and numbers.
	for (int counter = 0; counter < numberOfMines; counter++)
	{
		int r = rand() % tableSize;
		int c = rand() % tableSize;

		board[r][c].setNumber(-1); //plant mine.

		//plant number.
		for (int i = r; i < 3; i++)
		{
			for (int j = c; j < 3; j++)
			{
				if (board[i][j].getNumber() != -1)
					board[i][j].numberIncrease();
			}
		}
	}
}

void printTable(Block board[][tableSize])
{
	cout << setw(2) << fixed;
	for (int i = 0; i < tableSize + 1; i++)
	{
		if (i != 0)
			cout << setw(2) << fixed << i;
		for (int j = 0; j < tableSize; j++)
		{
			if (i == 0)
			{
				if (j == 0)
					cout << "  ";
				cout << setw(2) << fixed << char(j + 97);
			}
			else
				cout << setw(2) << fixed << '_';
		}
		cout << endl;
	}
}