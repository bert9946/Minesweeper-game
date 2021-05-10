#ifndef TABLE_H
#define TABLE_H
#include "block.h"

const int MAXTABLESIZE = 21;
class Table
{
private:
	int tableSize;
	int numberOfMines;
	void plantMines();
	void plantNumbers();
	Block **pArray;
	bool isValid(int, int) const;
	void newArray();

public:
	Table();
	Table(int);
	Table(int tableSize, int numberOfMines);
	~Table();
	void printTable() const;
};
#endif