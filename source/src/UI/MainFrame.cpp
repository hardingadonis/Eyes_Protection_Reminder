/*********************************************************************************
*                                                                                *
* MIT License                                                                    *
*                                                                                *
* Copyright (c) 2022 Harding Adonis, hoanghy0112, AlexPhoenix45                  *
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

#include <UI/MainFrame.hpp>
#include <UI/EPR_icon_512.xpm>

namespace EPR
{
	// IDs for the menu commands
	enum
	{
		EPR_Menu_Quit		= wxID_EXIT,
		EPR_Menu_Settings	= 10001,
		EPR_Menu_About		= wxID_ABOUT
	};

	wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
		EVT_MENU(EPR_Menu_Quit, MainFrame::OnQuit)
		EVT_MENU(EPR_Menu_Settings, MainFrame::OnSettings)
		EVT_MENU(EPR_Menu_About, MainFrame::OnAbout)
	wxEND_EVENT_TABLE()

	MainFrame::MainFrame(const wxString& _title, const wxSize& _size) :
		wxFrame(nullptr, wxStandardID::wxID_ANY, _title, wxDefaultPosition, _size, wxMINIMIZE_BOX | wxCLOSE_BOX | wxCAPTION),
		m_mainPanel(nullptr)
	{
		SetIcon(s_EPR_icon_512);

		CreateControls();
	}

	void MainFrame::OnQuit(wxCommandEvent& _event)
	{
		Close(true);

		_event.Skip();
	}

	void MainFrame::OnSettings(wxCommandEvent& _event)
	{
		_event.Skip();
	}

	void MainFrame::OnAbout(wxCommandEvent& _event)
	{
		_event.Skip();
	}

	void MainFrame::CreateControls()
	{
		// Menu bar - File
		wxMenu* _fileMenu = new wxMenu();
		_fileMenu->Append(EPR_Menu_Quit, "&Exit\tAlt-F4", "Quit this tool...");

		// Menu bar - Edit
		wxMenu* _editMenu = new wxMenu();
		_editMenu->Append(EPR_Menu_Settings, "&Settings\tAlt-S", "Show settings dialog...");

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