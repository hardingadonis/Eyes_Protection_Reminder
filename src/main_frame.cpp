#include "main_frame.hpp"
#include "EPR_icon.xpm"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title, const wxSize& size) :
	wxFrame(nullptr, wxStandardID::wxID_ANY, title, wxDefaultPosition, size, wxMINIMIZE_BOX | wxCLOSE_BOX | wxCAPTION)
{
	this->SetIcon(EPR_icon);
}