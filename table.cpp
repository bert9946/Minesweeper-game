#include <iostream>
#include <random>
#include <iomanip>
#include "block.h"
#include "table.h"
using namespace std;

Table::Table()
{
	this->tableSize = 9;
	this->numberOfMines = 10;

	newArray();
}

Table::Table(int gameMode)
{

	switch (gameMode)
	{
	case 1:
	default:
		this->tableSize = 9;
		this->numberOfMines = 10;
		break;
	case 2:
		this->tableSize = 16;
		this->numberOfMines = 40;
		break;
	case 3:
		this->tableSize = 20;
		this->numberOfMines = 99;
		break;
	}

	newArray();
}

Table::Table(int tableSize, int numberOfMines)
{
	this->tableSize = tableSize;
	this->numberOfMines = numberOfMines;

	newArray();
}

void Table::newArray()
{

	pArray = new Block *[MAXTABLESIZE];

	for (int i = 0; i < MAXTABLESIZE; i++)
		pArray[i] = new Block[MAXTABLESIZE];

	this->plantMines();
	this->plantNumbers();
}

Table::~Table()
{

	for (int i = 0; i < MAXTABLESIZE; i++)
		delete[] pArray[i];
	delete[] pArray;
}

void Table::plantMines()
{

	for (int i = 0; i < numberOfMines; i++)
		this->plantOneMine();
}

void Table::plantNumbers()
{

	for (int r = 0; r < tableSize; r++)
	{
		for (int c = 0; c < tableSize; c++)
		{
			if (!pArray[r][c].isMine())
				pArray[r][c].setNumber(0);
		}
	}

	for (int r = 0; r < tableSize; r++)
	{
		for (int c = 0; c < tableSize; c++)
		{

			if (pArray[r][c].isMine()) //if this is a mine.
			{

				for (int i = r - 1; i <= r + 1; i++)
				{
					for (int j = c - 1; j <= c + 1; j++)
					{
						if (isValid(i, j) && !(pArray[i][j].isMine()))
							pArray[i][j].numberIncrease();
					}
				}
			}
		}
	}
}

void Table::printTable() const
{
	cout << endl;

	//print column index(abc...).
	for (int i = 0; i < tableSize; i++)
	{
		if (i == 0)
			cout << "    ";
		cout << setw(2) << fixed << char(i + 97);
	}
	cout << "\n\n";

	for (int i = 0; i < tableSize; i++)
	{
		for (int j = 0; j < tableSize; j++)
		{
			//print row index(123...).
			if (j == 0)
				cout << setw(3) << i + 1 << " ";

			/*
			//for testing.
			if (pArray[i][j].getNumber() == -1)
				cout << setw(2) << fixed << '*';
			else
				cout << setw(2) << fixed << pArray[i][j].getNumber();
			*/

			// for implementation.
			if (!(pArray[i][j].getIsRevealed()))
			{
				if (pArray[i][j].getIsFlagged())
					cout << setw(2) << fixed << '$';
				else
					cout << setw(2) << fixed << '-';
			}

			else
			{
				if (pArray[i][j].isMine())
					cout << setw(2) << fixed << '@';
				else
					cout << setw(2) << fixed << pArray[i][j].getNumber();
			}
		}
		cout << endl;
	}
	cout << endl;
}

//Whether the coordinates is valid in the table.
bool Table::isValid(int i, int j) const
{
	return (i >= 0 && i <= tableSize && j >= 0 && j <= tableSize);
}

void Table::revealAllMines()
{
	for (int i = 0; i < tableSize; i++)
	{
		for (int j = 0; j < tableSize; j++)
		{
			if (pArray[i][j].isMine())
				pArray[i][j].reveal();
		}
	}
}

//If the block has no surrounding mine, reveal all of the surrounding block.
void Table::chainReveal(int i, int j)
{
	this->pArray[i][j].reveal();
	if (this->pArray[i][j].getNumber() == 0)
	{
		for (int x = i - 1; x <= i + 1; x++)
		{
			for (int y = j - 1; y <= j + 1; y++)
			{
				if (this->isValid(x, y) && !(x == i && y == j))
					if (!this->pArray[x][y].getIsRevealed())
					{
						this->chainReveal(x, y);
					}
			}
		}
	}
}

void Table::plantOneMine()
{
	//Random generator initialize.
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<int> unif(0, tableSize * tableSize - 1);

	int n = 0;
	while (n < 1)
	{
		int r = unif(generator);
		int c = r % tableSize;
		r /= tableSize;

		if (!pArray[r][c].isMine())
		{
			pArray[r][c].setNumber(-1); //plant mine.
			n++;
		}
		else
			continue;
	}
}

void Table::replantThisMine(int x, int y)
{
	this->pArray[x][y].setNumber(0);
	this->plantOneMine();
	this->plantNumbers();
}