#include "main_frame.hpp"
#include "EPR_icon.xpm"
#include <wx/wx.h>

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_MENU(wxStandardID::wxID_ABOUT, MainFrame::OnAboutMenu)
	EVT_CHOICE(10001, MainFrame::OnTimerValueSelected)
	EVT_BUTTON(10002, MainFrame::OnButtonStartPressed)
	EVT_BUTTON(10003, MainFrame::OnButtonStopPressed)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title, const wxSize& size) :
	wxFrame(nullptr, wxStandardID::wxID_ANY, title, wxDefaultPosition, size, wxMINIMIZE_BOX | wxCLOSE_BOX | wxCAPTION)
{
	SetIcon(EPR_icon);

	CreateControls();
}

void MainFrame::CreateControls()
{
	m_menuBar = new wxMenuBar();
	m_helpMenu = new wxMenu();

	m_helpMenu->Append(wxStandardID::wxID_ABOUT, "About");
	m_menuBar->Append(m_helpMenu, "Help");

	SetMenuBar(m_menuBar);

	//-----//

	wxPanel* panel_left = new wxPanel(this, wxStandardID::wxID_ANY, wxDefaultPosition, wxSize(300, 300));
	wxPanel* panel_right = new wxPanel(this, wxStandardID::wxID_ANY, wxDefaultPosition, wxSize(300, 300));

	wxBoxSizer* sizer = new wxBoxSizer(wxOrientation::wxHORIZONTAL);
	sizer->Add(panel_left, 1, wxStretch::wxEXPAND | wxDirection::wxALL, 2);
	sizer->Add(panel_right, 1, wxStretch::wxEXPAND | wxDirection::wxALL, 2);

	SetSizerAndFit(sizer);
	
	//-----//
	m_countdownTimer = new wxStaticText(panel_left, wxStandardID::wxID_ANY, "20:00", wxDefaultPosition, wxDefaultSize, wxAlignment::wxALIGN_CENTRE_HORIZONTAL | wxAlignment::wxALIGN_CENTRE_VERTICAL);
	m_countdownTimer->SetPosition(wxPoint(50, 95));
	m_countdownTimer->SetFont(wxFont(60, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false));

	//-----//

	m_IntroduceText = new wxStaticText(panel_right, wxStandardID::wxID_ANY, "How to use Eyes Protection Reminder:\n- Choose a value for timer.\n- Press \'Start\' button to start.\n- Press \'Stop\' to stop.", wxDefaultPosition, wxDefaultSize, wxAlignment::wxALIGN_CENTRE_VERTICAL);
	m_IntroduceText->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false));
	m_IntroduceText->SetPosition(wxPoint(18, 30));

	wxArrayString _choices;
	_choices.Add("5 minutes");
	_choices.Add("10 minutes");
	_choices.Add("15 minutes");
	_choices.Add("20 minutes");
	_choices.Add("25 minutes");
	_choices.Add("30 minutes");
	_choices.Add("35 minutes");
	_choices.Add("40 minutes");
	_choices.Add("45 minutes");
	_choices.Add("50 minutes");
	_choices.Add("55 minutes");
	_choices.Add("60 minutes");

	m_TimerValue = new wxChoice(panel_right, 10001, wxDefaultPosition, wxSize(100, 30), _choices);
	m_TimerValue->Select(3);
	m_TimerValue->SetPosition(wxPoint(100, 135));

	m_buttonStart = new wxButton(panel_right, 10002, "Start", wxPoint(40, 210), wxSize(90, 30));
	m_buttonStop = new wxButton(panel_right, 10003, "Stop", wxPoint(175, 210), wxSize(90, 30));

	//-----//

	CreateStatusBar();
	SetStatusText("Welcome to Eyes Protection Reminder...");
}

void MainFrame::OnAboutMenu(wxCommandEvent& event)
{
	wxMessageBox("MainFrame::OnAboutMenu");
}

void MainFrame::OnTimerValueSelected(wxCommandEvent& event)
{
	m_countdownTimer->SetLabel(GetTimerValue(m_TimerValue->GetCurrentSelection()));

	event.Skip();
}

void MainFrame::OnButtonStartPressed(wxCommandEvent& event)
{
	SetStatusText("Eyes Protection Reminder is still running...");

	event.Skip();
}

void MainFrame::OnButtonStopPressed(wxCommandEvent& event)
{
	SetStatusText("Eyes Protection Reminder was stopped!!!");

	event.Skip();
}

wxString MainFrame::GetTimerValue(int value)
{
	switch (value)
	{
	case 0:
		return "05:00";
		break;

	case 1:
		return "10:00";
		break;

	case 3:
		return "15:00";
		break;

	case 4:
		return "20:00";
		break;

	case 5:
		return "25:00";
		break;

	case 6:
		return "30:00";
		break;
	case 7:
		return "35:00";
		break;

	case 8:
		return "40:00";
		break;
	case 9:
		return "45:00";
		break;

	case 10:
		return "50:00";
		break;

	case 11:
		return "55:00";
		break;

	case 12:
		return "60:00";
		break;

	default:
		return "20:00";
	}
}