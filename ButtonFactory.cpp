#include "ButtonFactory.h"


wxButton* ButtonFactory::CreateButton(wxPanel* panel, const wxString label)
{
	return new wxButton(panel, wxID_ANY, label);
}
