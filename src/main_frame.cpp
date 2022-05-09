#include "about_dialog.hpp"
#include "main_frame.hpp"
#include "EPR_icon.xpm"
#include "EPR_icon_512.xpm"
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

	wxPanel* _panel_left = new wxPanel(this, wxStandardID::wxID_ANY, wxDefaultPosition, wxSize(300, 300));
	wxPanel* _panel_right = new wxPanel(this, wxStandardID::wxID_ANY, wxDefaultPosition, wxSize(300, 300));

	_panel_left->SetBackgroundColour(wxColor(255, 255, 255));
	_panel_right->SetBackgroundColour(wxColor(255, 255, 255));

	wxBoxSizer* sizer = new wxBoxSizer(wxOrientation::wxHORIZONTAL);
	sizer->Add(_panel_left, 1, wxStretch::wxEXPAND | wxDirection::wxALL, 2);
	sizer->Add(_panel_right, 1, wxStretch::wxEXPAND | wxDirection::wxALL, 2);

	SetSizerAndFit(sizer);
	
	//-----//

	m_countdownTimer = new wxStaticText(_panel_left, wxStandardID::wxID_ANY, "20:00", wxDefaultPosition, wxDefaultSize, wxAlignment::wxALIGN_CENTRE_HORIZONTAL | wxAlignment::wxALIGN_CENTRE_VERTICAL);
	m_countdownTimer->SetPosition(wxPoint(50, 95));
	m_countdownTimer->SetFont(wxFont(60, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false));

	m_timer = new wxTimer();
	m_timer->Bind(wxEVT_TIMER, &MainFrame::UpdateElapsedTime, this);
	m_timerValueInt = 0;

	//-----//

	m_introduceText = new wxStaticText(_panel_right, wxStandardID::wxID_ANY, "How to use Eyes Protection Reminder?\n- Choose a value for timer.\n- Press \'Start\' button to start.\n- Press \'Stop\' to stop.", wxDefaultPosition, wxDefaultSize, wxAlignment::wxALIGN_CENTRE_VERTICAL);
	m_introduceText->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false));
	m_introduceText->SetPosition(wxPoint(18, 30));

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

	m_timerValue = new wxChoice(_panel_right, 10001, wxDefaultPosition, wxSize(100, 30), _choices);
	m_timerValue->Select(3);
	m_timerValue->SetPosition(wxPoint(100, 135));

	m_buttonStart = new wxButton(_panel_right, 10002, "Start", wxPoint(40, 210), wxSize(90, 30));
	m_buttonStop = new wxButton(_panel_right, 10003, "Stop", wxPoint(175, 210), wxSize(90, 30));

	m_buttonStop->Enable(false);

	//-----//

	CreateStatusBar();
	SetStatusText("Welcome to Eyes Protection Reminder...");

	//-----//

	m_notificationMessage = new wxNotificationMessage("Eyes Protection Reminder", L"🐧🐧🐧 Hey bro. Relax now!!!", this);
	m_notificationMessage->SetIcon(EPR_icon_512);
}

void MainFrame::OnAboutMenu(wxCommandEvent& event)
{
	AboutDialog* _about_dialog = new AboutDialog(this, wxStandardID::wxID_ANY, "About!", wxDefaultPosition, wxSize(400, 250));

	_about_dialog->ShowModal();
	_about_dialog->Destroy();

	event.Skip();
}

void MainFrame::OnTimerValueSelected(wxCommandEvent& event)
{
	m_countdownTimer->SetLabel(GetTimerValue(m_timerValue->GetCurrentSelection()));

	event.Skip();
}

void MainFrame::OnButtonStartPressed(wxCommandEvent& event)
{
	SetStatusText("Eyes Protection Reminder is still running...");

	m_timerValue->Enable(false);
	m_buttonStart->Enable(false);
	m_buttonStop->Enable(true);

	m_timerValueInt = (m_timerValue->GetCurrentSelection() + 1) * 5 * 60;
	m_timer->Start(1000);

	event.Skip();
}

void MainFrame::OnButtonStopPressed(wxCommandEvent& event)
{
	SetStatusText("Eyes Protection Reminder was stopped!!!");

	m_timerValue->Enable(true);
	m_buttonStart->Enable(true);
	m_buttonStop->Enable(false);

	m_timer->Stop();
	m_countdownTimer->SetLabel(GetTimerValue(m_timerValue->GetCurrentSelection()));

	event.Skip();
}

void MainFrame::UpdateElapsedTime(wxTimerEvent& event)
{
	m_timerValueInt--;

	if (m_timerValueInt <= 0)
	{
		m_timerValueInt = (m_timerValue->GetCurrentSelection() + 1) * 5 * 60;

		m_notificationMessage->Show(20);
	}

	int _minute = m_timerValueInt / 60;
	wxString _minuteStr = std::to_string(_minute);

	if (_minute < 10)
	{
		_minuteStr = "0" + _minuteStr;
	}

	int _second = m_timerValueInt % 60;
	wxString _secondStr = std::to_string(_second);

	if (_second < 10)
	{
		_secondStr = "0" + _secondStr;
	}

	m_countdownTimer->SetLabelText(_minuteStr + ":" + _secondStr);
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

	case 2:
		return "15:00";
		break;

	case 3:
		return "20:00";
		break;

	case 4:
		return "25:00";
		break;

	case 5:
		return "30:00";
		break;

	case 6:
		return "35:00";
		break;

	case 7:
		return "40:00";
		break;

	case 8:
		return "45:00";
		break;

	case 9:
		return "50:00";
		break;

	case 10:
		return "55:00";
		break;

	case 11:
		return "60:00";
		break;

	default:
		return "20:00";
	}
}

int MainFrame::GetTimerValueWithInt(int value)
{
	switch (value)
	{
	case 0:
		return 5;
		break;

	case 1:
		return 10;
		break;

	case 2:
		return 15;
		break;

	case 3:
		return 20;
		break;

	case 4:
		return 25;
		break;

	case 5:
		return 30;
		break;

	case 6:
		return 35;
		break;

	case 7:
		return 40;
		break;

	case 8:
		return 45;
		break;

	case 9:
		return 50;
		break;

	case 10:
		return 55;
		break;

	case 11:
		return 60;
		break;

	default:
		return 20;
	}
}