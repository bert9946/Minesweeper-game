#include "block.h"
Block::Block()
{
	number = 0;
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

bool Block::IsMine() const
{
	return (this->getNumber() == -1);
}