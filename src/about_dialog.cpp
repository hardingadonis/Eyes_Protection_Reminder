#include "about_dialog.hpp"
#include "EPR_icon.xpm"

wxBEGIN_EVENT_TABLE(AboutDialog, wxDialog)
	EVT_BUTTON(10004, AboutDialog::OnButtonOKPressed)
wxEND_EVENT_TABLE()

AboutDialog::AboutDialog(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size) :
	wxDialog(parent, id, title, pos, size)
{
	wxPanel* _panel = new wxPanel(this, wxStandardID::wxID_ANY, pos, size);
	_panel->SetBackgroundColour(wxColor(255, 255, 255));

	wxStaticText* _title = new wxStaticText(_panel, wxStandardID::wxID_ANY, "Eyes Protection Reminder", wxPoint(55, 10));
	_title->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false));

	wxStaticText* _authors = new wxStaticText(_panel, wxStandardID::wxID_ANY, "Authors:\n- Harding Adonis\n- hoanghy0112\n- AlexPhoenix45", wxPoint(130, 60));
	_authors->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false));

	m_buttonOK = new wxButton(_panel, 10004, "OK", wxPoint(150, 170), wxSize(100, 25));
}

void AboutDialog::OnButtonOKPressed(wxCommandEvent& event)
{
	Destroy();
	wxLaunchDefaultBrowser("https://github.com/hardingadonis/Eyes_Protection_Reminder");

	event.Skip();
}