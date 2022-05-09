#include "application.hpp"
#include "main_frame.hpp"
#include <wx/wx.h>

bool Application::OnInit()
{
	MainFrame* main_frame = new MainFrame("Eyes Protection Reminder - v4.0.0", wxSize(600, 300));

	main_frame->Center();
	main_frame->Show();

	return true;
}

wxIMPLEMENT_APP(Application);