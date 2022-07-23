#include "Window.h"
#include "ButtonFactory.h"
#include "CalculatorProcessor.h"

wxBEGIN_EVENT_TABLE(Window, wxFrame)
EVT_BUTTON(wxID_ANY, Window::OnButtonClicked)
wxEND_EVENT_TABLE()

CalculatorProcessor* CalculatorProcessor::_calculatorProcessor;

Window::Window() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(500, 500), wxSize(800, 600))
{

	wxPanel* panel = new wxPanel(this, -1);

	//intialize textbox and buttons
	calcTextbox = new wxTextCtrl(panel, wxID_ANY);
	clear = ButtonFactory::CreateButton(panel, 1001, "Clear");
	zero = ButtonFactory::CreateButton(panel, 1002, "0");
	one = ButtonFactory::CreateButton(panel, 1002, "1");
	two = ButtonFactory::CreateButton(panel, 1002, "2");
	three = ButtonFactory::CreateButton(panel, 1002, "3");
	four = ButtonFactory::CreateButton(panel, 1002, "4");
	five = ButtonFactory::CreateButton(panel, 1002, "5");
	six = ButtonFactory::CreateButton(panel, 1002, "6");
	seven = ButtonFactory::CreateButton(panel, 1002, "7");
	eight = ButtonFactory::CreateButton(panel, 1002, "8");
	nine = ButtonFactory::CreateButton(panel, 1002, "9");
	mod = ButtonFactory::CreateButton(panel, 1003, "MOD");
	binary = ButtonFactory::CreateButton(panel, 1004, "BINARY");
	hex = ButtonFactory::CreateButton(panel, 1004, "HEX");
	decimal = ButtonFactory::CreateButton(panel, 1004, "DECIMAL");
	add = ButtonFactory::CreateButton(panel, 1003, "+");
	subtract = ButtonFactory::CreateButton(panel, 1003, "-");
	multiple = ButtonFactory::CreateButton(panel, 1003, "x");
	divide = ButtonFactory::CreateButton(panel, 1003, "/");
	sign = ButtonFactory::CreateButton(panel, 1005, "+/-");
	equal = ButtonFactory::CreateButton(panel, 1006, "=");


	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* TopUI = new wxBoxSizer(wxHORIZONTAL);

	TopUI->Add(calcTextbox, 1);
	TopUI->Add(clear, 0, wxRIGHT, 8);

	sizer->Add(TopUI, 0, wxEXPAND | wxTOP | wxBOTTOM, 10);

	sizer->Add(-1, 25);

	wxGridSizer* BottomUI = new wxGridSizer(5, 4, 3, 3);

	BottomUI->Add(mod, 0, wxEXPAND);
	BottomUI->Add(binary, 0, wxEXPAND);
	BottomUI->Add(hex, 0, wxEXPAND);
	BottomUI->Add(decimal, 0, wxEXPAND);
	BottomUI->Add(seven, 0, wxEXPAND);
	BottomUI->Add(eight, 0, wxEXPAND);
	BottomUI->Add(nine, 0, wxEXPAND);
	BottomUI->Add(sign, 0, wxEXPAND);
	BottomUI->Add(four, 0, wxEXPAND);
	BottomUI->Add(five, 0, wxEXPAND);
	BottomUI->Add(six, 0, wxEXPAND);
	BottomUI->Add(multiple, 0, wxEXPAND);
	BottomUI->Add(one, 0, wxEXPAND);
	BottomUI->Add(two, 0, wxEXPAND);
	BottomUI->Add(three, 0, wxEXPAND);
	BottomUI->Add(divide, 0, wxEXPAND);
	BottomUI->Add(zero, 0, wxEXPAND);
	BottomUI->Add(add, 0, wxEXPAND);
	BottomUI->Add(subtract, 0, wxEXPAND);
	BottomUI->Add(equal, 0, wxEXPAND);

	sizer->Add(BottomUI, 1, wxEXPAND);
	panel->SetSizer(sizer);

	Centre();

}

Window::~Window()
{
}

void Window::OnButtonClicked(wxCommandEvent& evt)
{
	wxButton* temp = dynamic_cast<wxButton*>(evt.GetEventObject());
	CalculatorProcessor* processor = CalculatorProcessor::GetInstance();

	if(temp->GetId() == 1001)
	{
		calcTextbox->SetLabel("");
	}
	else if (temp->GetId() == 1002)
	{	
		calcTextbox->SetLabel(calcTextbox->GetLabel() + temp->GetLabelText());

		if(!isRight)
		{
			processor->SetBaseNumber(wxAtoi(calcTextbox->GetLabel()));
		}
		else
		{
			rightSide = calcTextbox->GetLabel();
		}
		
	}
	else if (temp->GetId() == 1003 )
	{
		if (!isRight)
		{
			isRight = true;
			op = temp->GetLabel();
			calcTextbox->SetLabel("");
		}
		else if(!secondRight)
		{
			processor->setOperations(op, wxAtoi(calcTextbox->GetLabel()));
			op = temp->GetLabel();
			calcTextbox->SetLabel("");
			secondRight = true;
		}
		else
		{
			processor->SetBaseNumber(wxAtoi(processor->doOperations()));
			processor->setOperations(op, wxAtoi(calcTextbox->GetLabel()));
			op = temp->GetLabel();
			calcTextbox->SetLabel("");
		}

	}
	else if (temp->GetId() == 1004 && calcTextbox->GetLabel() != "")
	{
		if (temp->GetLabel() == "BINARY")
		{
			rightSide = calcTextbox->GetLabel();
			calcTextbox->SetLabel(processor->GetBinary());
		}
		else if (temp->GetLabel() == "HEX")
		{
			rightSide = calcTextbox->GetLabel();
			calcTextbox->SetLabel(processor->GetHex());
		}
		else
		{
			calcTextbox->SetLabel(processor->GetDecimal());
		}

	}
	else if (temp->GetId() == 1005)
	{
		if(!isRight)
		{
			calcTextbox->SetLabel(processor->Sign());
			processor->SetBaseNumber(wxAtoi(calcTextbox->GetLabel()));
		}
		else if(rightSide != "")
		{
			calcTextbox->SetLabel(processor->Sign(wxAtoi(rightSide)));
			rightSide = calcTextbox->GetLabel();
		}
		else
		{
			calcTextbox->SetLabel(processor->Sign(wxAtoi(calcTextbox->GetLabel())));
			processor->SetBaseNumber(wxAtoi(calcTextbox->GetLabel()));
		}



	}
	else if (temp->GetId() == 1006)
	{
		if(secondRight)
		{
			processor->SetBaseNumber(wxAtoi(processor->doOperations()));
		}
		processor->setOperations(op, wxAtoi(calcTextbox->GetLabel()));
		calcTextbox->SetLabel(processor->doOperations());
		op = "";
		processor->SetBaseNumber(wxAtoi(calcTextbox->GetLabel()));
		isRight = false;
		secondRight = false;
	}

	
}