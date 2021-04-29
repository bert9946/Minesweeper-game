#include <iostream>
#include "block.h"
using namespace std;

const int tableEdgeSize = 9;
char table[tableEdgeSize][tableEdgeSize];
Block minePosition[tableEdgeSize][tableEdgeSize];

void printTable();
void creatTable();

void game();

int main()
{
	creatTable();
	printTable();
	return 0;
}
void game()
{
}
void creatTable()
{
	for (int i = 0; i < tableEdgeSize; i++)
		for (int j = 0; j < tableEdgeSize; j++)
			table[i][j] = '_';
}

void printTable()
{
	for (int i = 0; i < tableEdgeSize; i++)
	{
		cout << char(i + 65) << ' ';
	}
	cout << endl;
	for (int i = 0; i < tableEdgeSize; i++)
	{
		for (int j = 0; j < tableEdgeSize; j++)
		{
			cout << table[i][j] << ' ';
		}
		cout << endl;
	}
}