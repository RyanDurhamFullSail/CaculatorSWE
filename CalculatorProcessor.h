#pragma once
#include "wx/wx.h"

class CalculatorProcessor
{
private:
	CalculatorProcessor() {}
	static CalculatorProcessor* _calculatorProcessor;
	int baseNum;
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

	wxString Add(int number)
	{
		return std::to_string((baseNum + number));
	}	
	
	wxString Subtract(int number)
	{
		return std::to_string((baseNum - number));
	}	
	
	wxString Multiple(int number)
	{
		return std::to_string((baseNum * number));
	}	
	
	wxString Divide(int number)
	{
		if(number != 0)
		{
			return std::to_string((baseNum / number));

		}

		return "ERROR";
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

	wxString Mod(int number)
	{
		if (number != 0)
		{
			return std::to_string((baseNum % number));

		}

		return "ERROR";
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

	wxString doOperations(wxString op, int num)
	{
		if (op == "+")
		{
			return _calculatorProcessor->Add(num);
		}
		else if (op == "-")
		{
			return _calculatorProcessor->Subtract(num);

		}
		else if (op == "x")
		{
			return _calculatorProcessor->Multiple(num);
		}
		else if (op == "/")
		{
			return _calculatorProcessor->Divide(num);

		}
		else if (op == "MOD")
		{
			return _calculatorProcessor->Mod(num);
		}

	}

};
