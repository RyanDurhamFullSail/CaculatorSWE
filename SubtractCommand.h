#pragma once
#include "IBaseCommand.h"

class SubtractCommand : public IBaseCommand
{
public:
	int leftSide;
	int rightSide;

	SubtractCommand(int left, int right)
	{
		leftSide = left;
		rightSide = right;
	}

	int doOperation()
	{
		return leftSide - rightSide;
	}

	int Execute()
	{
		return doOperation();
	}
};

