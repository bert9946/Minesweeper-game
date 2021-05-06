#include <iostream>
#include <random>
#include <iomanip>
#include "block.h"
using namespace std;

const unsigned int numberOfMines = 10;
const unsigned int tableSize = 9;
Block gameBoard[tableSize][tableSize];

void plantMines(Block[][tableSize]);
void plantNumbers(Block[][tableSize]);
void printTable(Block[][tableSize]);

int main()
{
	plantMines(gameBoard);
	plantNumbers(gameBoard);
	printTable(gameBoard);
	return 0;
}

void plantMines(Block board[][tableSize])
{

	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<int> unif(0, 80);

	int n = 0;

	while (n < numberOfMines)
	{
		int r = unif(generator);
		int c = r % tableSize;
		r /= 9;
		// cout << r << ' ' << c << endl;
		if (board[r][c].getNumber() != -1)
		{
			board[r][c].setNumber(-1); //plant mine.
			n++;
		}
		else
			continue;
	}
}

void plantNumbers(Block board[][tableSize])
{
	int r, c, i, j;
	for (r = 0; r < tableSize; r++)
	{
		for (c = 0; c < tableSize; c++)
		{

			if (board[r][c].getNumber() == -1) //if this is a mine.
			{

				for (i = r - 1; i <= r + 1; i++)
				{
					for (j = c - 1; j <= c + 1; j++)
					{
						if (i >= 0 && i <= tableSize && j >= 0 && j <= tableSize && !(i == r && j == c) &&
							board[i][j].getNumber() != -1)
							board[i][j].numberIncrease();
					}
				}
			}
		}
	}
}

void printTable(Block board[][tableSize])
{
	//print column index(abc...).
	for (int i = 0; i < tableSize; i++)
	{
		if (i == 0)
			cout << "  ";
		cout << setw(2) << fixed << char(i + 97);
	}
	cout << "\n\n";

	for (int i = 0; i < tableSize; i++)
	{
		for (int j = 0; j < tableSize; j++)
		{
			//print row index(123...).
			if (j == 0)
				cout << tableSize - i << " ";

			if (board[i][j].getNumber() == -1)
				cout << setw(2) << fixed << '*';
			else
				cout << setw(2) << fixed << board[i][j].getNumber();
		}
		cout << endl;
	}
}