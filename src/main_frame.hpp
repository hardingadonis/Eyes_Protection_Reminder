#pragma once

#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title, const wxSize& size);

	void CreateControls();

	void OnAboutMenu(wxCommandEvent& event);

	void OnTimerValueSelected(wxCommandEvent& event);

	void OnButtonStartPressed(wxCommandEvent& event);
	void OnButtonStopPressed(wxCommandEvent& event);

private:
	wxString GetTimerValue(int value);

private:
	wxStaticText*	m_countdownTimer;

	wxStaticText*	m_IntroduceText;
	wxChoice*		m_TimerValue;

	wxButton*		m_buttonStart;
	wxButton*		m_buttonStop;

	wxMenuBar*		m_menuBar;
	wxMenu*			m_helpMenu;

public:
	wxDECLARE_EVENT_TABLE();
};