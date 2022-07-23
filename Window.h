#pragma once
#include "wx/wx.h"
#include "CalculatorProcessor.h"


class Window : public wxFrame
{
public:
	Window();
	~Window();

public:
	//Buttons
	wxButton *zero;
	wxButton *one;
	wxButton *two;
	wxButton *three;
	wxButton *four;
	wxButton *five;
	wxButton *six;
	wxButton *seven;
	wxButton *eight;
	wxButton *nine;
	wxButton *mod;
	wxButton *binary;
	wxButton *hex;
	wxButton *decimal;
	wxButton *add;
	wxButton *subtract;
	wxButton *multiple;
	wxButton *divide;
	wxButton *sign;
	wxButton *clear;
	wxButton *equal;

	//Textbox
	wxTextCtrl *calcTextbox;
	wxButton* temp;
	CalculatorProcessor* processor;
	bool secondRight = false;
	bool isRight = false;
	wxString rightSide = "";
	wxString op = "";

	void OnButtonClicked(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

