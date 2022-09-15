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