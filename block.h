#ifndef BLOCK_H
#define BLOCK_H
class Block
{
public:
	Block();
	void setNumber(int);
	int getNumber() const;
	void numberIncrease();
	bool getIsRealed() const;

private:
	int number;
	bool isRealed;
};
#endif