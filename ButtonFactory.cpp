#include "ButtonFactory.h"


wxButton* ButtonFactory::CreateButton(wxPanel* panel, int id, const wxString label)
{
	return new wxButton(panel, id, label);
}
