#include "application.hpp"
#include "main_frame.hpp"
#include <wx/wx.h>

bool Application::OnInit()
{
	m_checker = new wxSingleInstanceChecker;

	if (m_checker->IsAnotherRunning())
	{
		wxLogError(_("Another program instance is already running, aborting."));

		delete m_checker;
		m_checker = nullptr;

		return false;
	}


	MainFrame* main_frame = new MainFrame("Eyes Protection Reminder - v4.0.0", wxSize(600, 300));

	main_frame->Center();
	main_frame->Show();

	return true;
}

int Application::OnExit()
{
	delete m_checker;
	m_checker = nullptr;

	return 0;
}

wxIMPLEMENT_APP(Application);