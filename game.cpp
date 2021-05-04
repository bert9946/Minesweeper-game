#include "game.h"

Game::Game()
{
	tableSize = 9;
	numberOfMine = 40;
}

Game::Game(int gameMode)
{
	int tableSize;
	switch (gameMode)
	{
	case 2:
		tableSize = 16;
		numberOfMine = 40;
		break;
	case 3:
		tableSize = 24;
		numberOfMine = 99;
		break;
	case 1:
	default:
		tableSize = 9;
		numberOfMine = 10;
		break;
	}
}

void Game::createTable()
{
}