#pragma once

#include <wx/wx.h>
#include <wx/notifmsg.h>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title, const wxSize& size);
	virtual ~MainFrame() = default;

	void CreateControls();

	void OnAboutMenu(wxCommandEvent& event);

	void OnTimerValueSelected(wxCommandEvent& event);

	void OnButtonStartPressed(wxCommandEvent& event);
	void OnButtonStopPressed(wxCommandEvent& event);

	void UpdateElapsedTime(wxTimerEvent& event);

private:
	wxString GetTimerValue(int value);
	int GetTimerValueWithInt(int value);

private:
	wxStaticText*			m_countdownTimer;

	wxStaticText*			m_introduceText;
	wxChoice*				m_timerValue;

	wxButton*				m_buttonStart;
	wxButton*				m_buttonStop;

	wxMenuBar*				m_menuBar;
	wxMenu*					m_helpMenu;

	wxTimer*				m_timer;
	int						m_timerValueInt;

	wxNotificationMessage*	m_notificationMessage;

public:
	wxDECLARE_EVENT_TABLE();
};