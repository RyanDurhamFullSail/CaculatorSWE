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
		if (rightSide != 0)
		{
			return leftSide % rightSide;
		}

		return -1;
	}

	int Execute()
	{
		return doOperation();
	}
};

