/*********************************************************************************
*                                                                                *
* MIT License                                                                    *
*                                                                                *
* Copyright (c) 2022 Minh Vương                                                  *
*                                                                                *
* Permission is hereby granted, free of charge, to any person obtaining a copy   *
* of this software and associated documentation files (the "Software"), to deal  *
* in the Software without restriction, including without limitation the rights   *
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell      *
* copies of the Software, and to permit persons to whom the Software is          *
* furnished to do so, subject to the following conditions:                       *
*                                                                                *
* The above copyright notice and this permission notice shall be included in all *
* copies or substantial portions of the Software.                                *
*                                                                                *
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR     *
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,       *
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE    *
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER         *
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  *
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  *
* SOFTWARE.                                                                      *
*                                                                                *
*********************************************************************************/

#include <wx/aboutdlg.h>
#include <wx/generic/aboutdlgg.h>
#include <wx/fileconf.h>
#include <wx/stdpaths.h>

#include <UI/MainFrame.hpp>
#include <UI/EPR_icon_64.xpm>
#include <UI/EPR_icon_512.xpm>
#include <Utils/Config.hpp>

namespace EPR
{
	// IDs for the menu commands
	enum EPR_Menu
	{
		EPR_Menu_Hide		= 10001,
		EPR_Menu_Quit		= wxID_EXIT,
		EPR_Menu_Settings	= 10002,
		EPR_Menu_About		= wxID_ABOUT
	};

	wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
		EVT_MENU(EPR_Menu_Hide, MainFrame::OnMenuHide)
		EVT_MENU(EPR_Menu_Quit, MainFrame::OnMenuQuit)
		EVT_MENU(EPR_Menu_Settings, MainFrame::OnMenuSettings)
		EVT_MENU(EPR_Menu_About, MainFrame::OnMenuAbout)
	wxEND_EVENT_TABLE()

	MainFrame::MainFrame(const wxString& _title, const wxSize& _size) :
		wxFrame(nullptr, wxStandardID::wxID_ANY, _title, wxDefaultPosition, _size, wxMINIMIZE_BOX | wxCLOSE_BOX | wxCAPTION),
		m_mainPanel(nullptr)
	{
		SetIcon(s_EPR_icon_512);

		CreateControls();
	}

	void MainFrame::OnMenuHide(wxCommandEvent& _event)
	{
		Show(false);

		_event.Skip();
	}

	void MainFrame::OnMenuQuit(wxCommandEvent& _event)
	{
		Close(true);

		_event.Skip();
	}

	void MainFrame::OnMenuSettings(wxCommandEvent& _event)
	{
		_event.Skip();
	}

	void MainFrame::OnMenuAbout(wxCommandEvent& _event)
	{
		wxAboutDialogInfo _aboutInfo;

		// Set the information for about dialog
		_aboutInfo.SetName(wxTheApp->GetAppName());
		_aboutInfo.SetVersion("- v4.1.0");
		_aboutInfo.SetIcon(s_EPR_icon_64);
		_aboutInfo.SetCopyright("Copyright (c) 2022 " + wxString::FromUTF8("Minh Vương.") + "\nAll rights reserved.");
		_aboutInfo.SetDescription("A small tool to remind you to\nprotect your eyes with the 20:20:20 rule.");

		_aboutInfo.SetWebSite("https://github.com/hardingadonis/Eyes_Protection_Reminder", "Source Code");

		_aboutInfo.SetLicense(
			"MIT License\n"
			"\n" +
			wxString::FromUTF8("Copyright (c) 2022 Minh Vương\n") +
			"\n"
			"Permission is hereby granted, free of charge, to any person obtaining a copy\n"
			"of this software and associated documentation files (the \"Software\"), to deal\n"
			"in the Software without restriction, including without limitation the rights\n"
			"to use, copy, modify, merge, publish, distribute, sublicense, and/or sell\n"
			"copies of the Software, and to permit persons to whom the Software is\n"
			"furnished to do so, subject to the following conditions:\n"
			"\n"
			"The above copyright notice and this permission notice shall be included in all\n"
			"copies or substantial portions of the Software.\n"
			"\n"
			"THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n"
			"IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,y\n"
			"FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n"
			"AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n"
			"LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n"
			"OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE\n"
			"SOFTWARE.\n"
		);

		_aboutInfo.AddDeveloper(wxString::FromUTF8("Minh Vương"));
		_aboutInfo.AddDeveloper("Contributors");

		_aboutInfo.AddDocWriter(wxString::FromUTF8("Minh Vương"));
		_aboutInfo.AddDocWriter("Contributors");

		// Generate the about dialog
		wxGenericAboutBox(_aboutInfo, this);

		_event.Skip();
	}

	void MainFrame::CreateControls()
	{
		// Menu bar - File
		wxMenu* _fileMenu = new wxMenu();
		_fileMenu->Append(EPR_Menu_Hide, "&Hide\tF2", "Hide this tool...");
		_fileMenu->Append(EPR_Menu_Quit, "&Exit\tAlt-F4", "Quit this tool...");

		// Menu bar - Edit
		wxMenu* _editMenu = new wxMenu();
		_editMenu->Append(EPR_Menu_Settings, "&Settings\tF3", "Show settings dialog...");

		// Menu bar - Help
		wxMenu* _helpMenu = new wxMenu();
		_helpMenu->Append(EPR_Menu_About, "&About\tF1", "Show about dialog...");

		// Menu bar - all
		wxMenuBar* _menuBar = new wxMenuBar();
		_menuBar->Append(_fileMenu, "&File");
		_menuBar->Append(_editMenu, "&Edit");
		_menuBar->Append(_helpMenu, "&Help");

		// Set menu bar for MainFrame
		SetMenuBar(_menuBar);

		// Create main panel
		m_mainPanel = new MainPanel(this);

		// Create status bar
		CreateStatusBar(2);
		SetStatusText("Welcome to Eyes Protection Reminder!");
	}
}