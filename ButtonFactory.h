#include "wx/wx.h"


class ButtonFactory
{
public:
	static wxButton* CreateButton(wxPanel* panel, int id, const wxString label);
};

