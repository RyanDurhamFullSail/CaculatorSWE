#pragma once
#include "IBaseCommand.h"

class MultipleCommand : public IBaseCommand
{
public:
	int leftSide;
	int rightSide;

	MultipleCommand(int left, int right)
	{
		leftSide = left;
		rightSide = right;
	}

	int doOperation()
	{
		return leftSide * rightSide;
	}

	int Execute()
	{
		return doOperation();
	}
};

