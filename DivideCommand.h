#pragma once
#include "IBaseCommand.h"

class DivideCommand : public IBaseCommand
{
public:
	int leftSide;
	int rightSide;

	DivideCommand(int left, int right)
	{
		leftSide = left;
		rightSide = right;
	}

	int doOperation()
	{
		return leftSide / rightSide;
	}

	int Execute()
	{
		return doOperation();
	}
};

