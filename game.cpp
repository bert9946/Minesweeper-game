#include "game.h"
#include <ctime>
#include <cstdlib>

const int tableSize = 9;
const int numberOfSize = 10;
Game::Game()
{
}

void Game::createMineTable()
{
	int **mine = new int *[tableSize];
	for (int i = 0; i < tableSize; i++)
	{
		mine[i] = new int[tableSize];
	}
	srand(static_cast<unsigned int>(time(0)));

	for (int i = 0; i < numberOfSize; i++)
	{
		mine[rand() % (tableSize * tableSize)];
	}

	for (int i = 0; i < tableSize; i++)
		for (int j = 0; j < tableSize; j++)
		{
			mine[i][j];
		}
}