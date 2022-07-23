#pragma once
#include "IBaseCommand.h"

class AddCommand : public IBaseCommand
{
public:
	int leftSide;
	int rightSide;
	AddCommand();
	AddCommand(int left, int right)
	{
		leftSide = left;
		rightSide = right;
	}

	int doOperation()
	{
		return leftSide + rightSide;
	}

	int Execute()
	{
		return doOperation();
	}
};

