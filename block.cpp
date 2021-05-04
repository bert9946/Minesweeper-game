#include "block.h"
Block::Block()
{
	this->isRealed = false;
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

bool Block::getIsRealed() const
{
	return isRealed;
}