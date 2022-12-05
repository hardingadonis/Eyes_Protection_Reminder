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

#pragma once

#include <wx/wx.h>
#include <wx/taskbar.h>

namespace EPR
{
	class MainPanel : public wxPanel
	{
	public:
		MainPanel(wxWindow* _parent, wxTaskBarIcon* _taskBarIcon);

		void OnStartButtonPressed(wxCommandEvent& _event);
		void OnStopButtonPressed(wxCommandEvent& _event);

		void OnTimerElapsed(wxTimerEvent& _event);
		void OnRestedElapsed(wxTimerEvent& _event);

	private:
		void CreateControls();

		void ResetTimer();

	private:
		wxStaticText*	m_timerValue;
		wxStaticText*	m_restedValue;

		wxTimer*		m_timer;
		wxTimer*		m_rested;

		wxButton*		m_startButton;
		wxButton*		m_stopButton;

		wxFrameBase*	m_parent;
		wxTaskBarIcon*	m_taskBarIcon;

	public:
		wxDECLARE_EVENT_TABLE();
	};
}