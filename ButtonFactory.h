#include "wx/wx.h"


class ButtonFactory
{
public:
	static wxButton* CreateButton(wxPanel* panel,const wxString label);
};

