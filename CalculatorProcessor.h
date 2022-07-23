#pragma once
#include "wx/wx.h"
#include "IBaseCommand.h"
#include "AddCommand.h"
#include "SubtractCommand.h"
#include "MultipleCommand.h"
#include "DivideCommand.h"
#include "ModCommand.h"
#include <vector>

class CalculatorProcessor
{
private:
	CalculatorProcessor() {}
	static CalculatorProcessor* _calculatorProcessor;
	int baseNum;
	std::vector<IBaseCommand*> commands;
public:
	static CalculatorProcessor* GetInstance() 
	{
		if (_calculatorProcessor == nullptr)
		{
			_calculatorProcessor = new CalculatorProcessor();
		}
		return _calculatorProcessor;
	}

	void SetBaseNumber(int number)
	{
		baseNum = number;
	}

	CalculatorProcessor(CalculatorProcessor& other) = delete;
	void operator=(const CalculatorProcessor& other) = delete;

	void Add(int number)
	{
		AddCommand* add = new AddCommand(baseNum, number);

		commands.push_back(add);
	}	
	
	void Subtract(int number)
	{
		SubtractCommand* sub = new SubtractCommand(baseNum, number);

		commands.push_back(sub);
	}
	
	void Multiple(int number)
	{
		MultipleCommand* multiple = new MultipleCommand(baseNum, number);

		commands.push_back(multiple);
	}
	
	void Divide(int number)
	{
		DivideCommand* divide = new DivideCommand(baseNum, number);

		commands.push_back(divide);
	}

	wxString Sign()
	{
		return  std::to_string((baseNum * -1));
	}	
	
	wxString Sign(int num)
	{
		return  std::to_string((num * -1));
	}

	wxString GetDecimal()
	{
		return std::to_string(baseNum);
	}

	void Mod(int number)
	{
		ModCommand* mod = new ModCommand(baseNum, number);

		commands.push_back(mod);
	}

	wxString GetHex()
	{
		std::string results = "";
		int number = std::abs(baseNum);
		bool neg = baseNum < 0;

		while(number >= 0)
		{
			int mod = number % 16;
			if(mod < 10)
			{
				results = std::to_string(mod) + results;
			}
			else if (mod == 10)
			{
				results = "A" + results;
			}
			else if (mod == 11)
			{
				results = "B" + results;
			}
			else if (mod == 12)
			{
				results = "C" + results;
			}
			else if (mod == 13)
			{
				results = "D" + results;
			}
			else if (mod == 14)
			{
				results = "E" + results;
			}
			else if (mod == 15)
			{
				results = "F" + results;
			}

			number = number / 16;
		}
		if(neg)
		{
			results = "-" + results;
		}
		return results;
	}

	wxString GetBinary()
	{
		std::string results = "";
		int number = baseNum;

		for (int i = 0; i < 32; i++)
		{
			if (number % 2 == 0)
			{
				results = "0" + results;
			}
			else
			{
				results = "1" + results;
			}

			number = number / 2;
		}

		return results;

	}

	void setOperations(wxString op, int num)
	{
		if (op == "+")
		{
			_calculatorProcessor->Add(num);
		}
		else if (op == "-")
		{
			_calculatorProcessor->Subtract(num);

		}
		else if (op == "x")
		{
			_calculatorProcessor->Multiple(num);
		}
		else if (op == "/")
		{
			_calculatorProcessor->Divide(num);

		}
		else if (op == "MOD")
		{
			_calculatorProcessor->Mod(num);
		}

	}

	wxString doOperations()
	{
		int results = 0;

		for(int i = 0; i < commands.size(); i++)
		{
			results += commands[i]->Execute();
		}

		for (int i = 0; i < commands.size(); i++)
		{
			delete commands[i];
		}

		commands.clear();

		return std::to_string(results);
	}

};
