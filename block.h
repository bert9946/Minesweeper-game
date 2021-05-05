#ifndef BLOCK_H
#define BLOCK_H
class Block
{
public:
	Block();
	void setNumber(int);
	int getNumber() const;
	bool getIsRevealed() const;
	void numberIncrease();

private:
	int number; //number of surrounding mines. -1 means this is mine.
	bool isRevealed;
};
#endif