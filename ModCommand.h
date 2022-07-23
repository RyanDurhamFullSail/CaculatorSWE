#pragma once
#include "IBaseCommand.h"

class ModCommand : public IBaseCommand
{
public:
	int leftSide;
	int rightSide;

	ModCommand(int left, int right)
	{
		leftSide = left;
		rightSide = right;
	}

	int doOperation()
	{
		return leftSide % rightSide;
	}

	int Execute()
	{
		return doOperation();
	}
};

