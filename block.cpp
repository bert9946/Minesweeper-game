#include "block.h"
Block::Block()
{
	this->number = 0;
}

void Block::setNumber(int number)
{
	this->number = number;
}

void Block::numberIncrease()
{
	this->number++;
}

int Block::getNumber() const
{
	return number;
}

bool Block::getIsRevealed() const
{
	return isRevealed;
}

bool Block::isMine() const
{
	return (this->number == -1);
}