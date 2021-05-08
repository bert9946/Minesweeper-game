#ifndef TABLE_H
#define TABLE_H
#include "block.h"

const int maxTableSize = 24;
class Table
{
private:
	int tableSize;
	int numberOfMines;
	void plantMines();
	void plantNumbers();
	Block **pArray;
	bool isValid(int, int) const;

public:
	Table();
	~Table();
	void printTable() const;
};
#endif