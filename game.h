#ifndef GAME_H
#define GAME_H
class Game
{
public:
	Game();
	Game(int);
	void printTable();
	void createTable();

private:
	int tableSize;
	int numberOfMine;
};
#endif