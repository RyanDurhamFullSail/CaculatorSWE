#include "Window.h"
#include "ButtonFactory.h"


wxBEGIN_EVENT_TABLE(Window, wxFrame)
	EVT_BUTTON(wxID_ANY, Window::OnButtonClicked)
wxEND_EVENT_TABLE()

Window::Window() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(500, 500), wxSize(800, 600))
{

	wxPanel* panel = new wxPanel(this, -1);

	//intialize textbox and buttons
	calcTextbox = new wxTextCtrl(panel, wxID_ANY);
	clear = ButtonFactory::CreateButton(panel, "Clear");
	zero = ButtonFactory::CreateButton(panel, "0");
	one = ButtonFactory::CreateButton(panel, "1");
	two = ButtonFactory::CreateButton(panel, "2");
	three = ButtonFactory::CreateButton(panel, "3");
	four = ButtonFactory::CreateButton(panel, "4");
	five = ButtonFactory::CreateButton(panel, "5");
	six = ButtonFactory::CreateButton(panel, "6");
	seven = ButtonFactory::CreateButton(panel, "7");
	eight = ButtonFactory::CreateButton(panel, "8");
	nine = ButtonFactory::CreateButton(panel, "9");
	mod = ButtonFactory::CreateButton(panel, "MOD");
	binary = ButtonFactory::CreateButton(panel, "BINARY");
	hex = ButtonFactory::CreateButton(panel, "HEX");
	decimal = ButtonFactory::CreateButton(panel, "DECIMAL");
	add = ButtonFactory::CreateButton(panel, "+");
	subtract = ButtonFactory::CreateButton(panel, "-");
	multiple = ButtonFactory::CreateButton(panel, "*");
	divide = ButtonFactory::CreateButton(panel, "x");
	sign = ButtonFactory::CreateButton(panel, "+/-");
	equal = ButtonFactory::CreateButton(panel, "=");


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

	calcTextbox->SetLabel(calcTextbox->GetLabel() + temp->GetLabel());
}