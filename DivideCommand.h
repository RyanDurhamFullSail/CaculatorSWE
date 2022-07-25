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
		if(rightSide != 0)
		{
			return leftSide / rightSide;
		}

		return -1;
	}

	int Execute()
	{
		return doOperation();
	}
};

