#include "block.h"

int Block::numberOfFlag = 0;

Block::Block()
{
	this->number = 0;
	this->isFlagged = false;
	this->isRevealed = false;
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

bool Block::getIsFlagged() const
{
	return isFlagged;
}

bool Block::isMine() const
{
	return (this->number == -1);
}

void Block::reveal()
{
	this->isRevealed = true;
}

void Block::flag()
{
	if (!this->isRevealed)
	{
		if (!this->isFlagged)
		{
			this->isFlagged = true;
			numberOfFlag++;
		}
		else
		{
			this->isFlagged = false;
			numberOfFlag--;
		}
	}
}

int Block::getNumberOfFlag()
{
	return numberOfFlag;
}