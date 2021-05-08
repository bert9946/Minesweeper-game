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

	pArray = new Block *[maxTableSize];

	for (int i = 0; i < maxTableSize; i++)
		pArray[i] = new Block[maxTableSize];

	this->plantMines();
	this->plantNumbers();
}

Table::~Table()
{

	for (int i = 0; i < maxTableSize; i++)
		delete[] pArray[i];
	delete[] pArray;
}

void Table::plantMines()
{

	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<int> unif(0, tableSize * tableSize - 1);

	int n = 0;

	while (n < numberOfMines)
	{
		int r = unif(generator);
		int c = r % tableSize;
		r /= tableSize;
		// cout << r << ' ' << c << endl;
		if (pArray[r][c].getNumber() != -1)
		{
			pArray[r][c].setNumber(-1); //plant mine.
			n++;
		}
		else
			continue;
	}
}

void Table::plantNumbers()
{
	int r, c, i, j;
	for (r = 0; r < tableSize; r++)
	{
		for (c = 0; c < tableSize; c++)
		{

			if (pArray[r][c].getNumber() == -1) //if this is a mine.
			{

				for (i = r - 1; i <= r + 1; i++)
				{
					for (j = c - 1; j <= c + 1; j++)
					{
						if (isValid(i, j) && !(pArray[i][j].IsMine()))
							pArray[i][j].numberIncrease();
					}
				}
			}
		}
	}
}

void Table::printTable() const
{
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

			if (pArray[i][j].getNumber() == -1)
				cout << setw(2) << fixed << '*';
			else
				cout << setw(2) << fixed << pArray[i][j].getNumber();
		}
		cout << endl;
	}
}

bool Table::isValid(int i, int j) const
{
	return (i >= 0 && i <= tableSize && j >= 0 && j <= tableSize);
}