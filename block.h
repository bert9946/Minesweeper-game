#ifndef BLOCK_H
#define BLOCK_H
class Block
{
public:
	Block();
	void setNumber(int);
	int getNumber() const;
	bool getIsRevealed() const;
	bool getIsFlagged() const;
	void numberIncrease();
	bool isMine() const;
	void reveal();
	void flag();
	static int getNumberOfFlag();
	friend class game;

private:
	int number; //number of surrounding mines. -1 means this is mine.
	bool isRevealed;
	bool isFlagged;
	static int numberOfFlag;
};
#endif