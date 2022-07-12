#include "Window.h"


wxBEGIN_EVENT_TABLE(Window, wxFrame)
wxEND_EVENT_TABLE()

Window::Window() : wxFrame(nullptr, wxID_ANY,"Calculator", wxPoint(500,500), wxSize(800,600))
{

	wxPanel* panel = new wxPanel(this, -1);

	//intialize textbox and buttons
	calcTextbox = new wxTextCtrl(panel, wxID_ANY);
	clear = new wxButton(panel, wxID_ANY,"Clear");
	zero = new wxButton(panel, wxID_ANY,"0");
	one = new wxButton(panel, wxID_ANY,"1");
	two = new wxButton(panel, wxID_ANY, "2");
	three = new wxButton(panel, wxID_ANY, "3");
	four = new wxButton(panel, wxID_ANY, "4");
	five = new wxButton(panel, wxID_ANY, "5");
	six = new wxButton(panel, wxID_ANY, "6");
	seven = new wxButton(panel, wxID_ANY, "7");
	eight = new wxButton(panel, wxID_ANY, "8");
	nine = new wxButton(panel, wxID_ANY, "9");
	mod = new wxButton(panel, wxID_ANY, "MOD");
	binary = new wxButton(panel, wxID_ANY, "BINARY");
	hex = new wxButton(panel, wxID_ANY, "HEX");
	decimal = new wxButton(panel, wxID_ANY, "DECIMAL");
	add = new wxButton(panel, wxID_ANY, "+");
	subtract = new wxButton(panel, wxID_ANY, "-");
	multiple = new wxButton(panel, wxID_ANY, "*");
	divide = new wxButton(panel, wxID_ANY, "/");
	sign = new wxButton(panel, wxID_ANY, "+/-");
	equal = new wxButton(panel, wxID_ANY, "=");

	wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer *TopUI = new wxBoxSizer(wxHORIZONTAL);

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