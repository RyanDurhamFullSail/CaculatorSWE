#include "Calculator.h"
#include "Window.h"

wxIMPLEMENT_APP(Calculator);

bool Calculator::OnInit()
{
	window = new Window();
	window->Show();
	return true;
}