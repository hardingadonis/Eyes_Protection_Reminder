#include "application.hpp"
#include "main_frame.hpp"
#include <wx/wx.h>

bool Application::OnInit()
{
	MainFrame* main_frame = new MainFrame("C++ GUI Application");

	main_frame->SetClientSize(800, 600);
	main_frame->Center();

	main_frame->Show();

	return true;
}

wxIMPLEMENT_APP(Application);