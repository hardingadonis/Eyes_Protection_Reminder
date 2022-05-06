#include "main_frame.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>

MainFrame::MainFrame(const wxString& title) :
	wxFrame(nullptr, wxStandardID::wxID_ANY, title)
{
	wxPanel* panel = new wxPanel(this);

	wxButton* button = new wxButton(panel, wxStandardID::wxID_ANY, "Button", wxPoint(150, 50), wxSize(100, 35), wxBU_TOP);

	wxCheckBox* checkBox = new wxCheckBox(panel, wxStandardID::wxID_ANY, "Checkbox", wxPoint(500, 50));

	wxStaticText* staticText = new wxStaticText(panel, wxStandardID::wxID_ANY, "StaticText - NOT Editable", wxPoint(120, 150));

	wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxStandardID::wxID_ANY, "TextCtrl - editable", wxPoint(500, 145), wxSize(200, -1));

	wxSlider* slider = new wxSlider(panel, wxStandardID::wxID_ANY, 25, 0, 100, wxPoint(100, 250), wxSize(200, -1));

	wxGauge* gauge = new wxGauge(panel, wxStandardID::wxID_ANY, 100, wxPoint(500, 255), wxSize(200, -1));
	gauge->SetValue(70);

	wxArrayString choices;
	choices.Add("Item A");
	choices.Add("Item B");
	choices.Add("Item C");

	wxChoice* choice = new wxChoice(panel, wxStandardID::wxID_ANY, wxPoint(150, 375), wxSize(100, -1), choices);
	choice->Select(0);

	wxSpinCtrl* spinCtrl = new wxSpinCtrl(panel, wxStandardID::wxID_ANY, "SHIT", wxPoint(550, 375), wxSize(100, -1));
}