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

#include <wx/statline.h>

#include <UI/MainPanel.hpp>
#include <Utils/Config.hpp>

namespace EPR
{
	// Variables is used to storage the value of time remaining
	static int s_timer_time_remaining = 0;
	static int s_timer_rested_remaining = 0;

	// IDs for the controls
	enum EPR_Button
	{
		EPR_Button_Start	= 11001,
		EPR_Button_Stop		= 11002
	};

	wxBEGIN_EVENT_TABLE(MainPanel, wxPanel)
		EVT_BUTTON(EPR_Button_Start, MainPanel::OnStartButtonPressed)
		EVT_BUTTON(EPR_Button_Stop, MainPanel::OnStopButtonPressed)
	wxEND_EVENT_TABLE()

	MainPanel::MainPanel(wxWindow* _parent) :
		wxPanel(_parent, wxID_ANY),
		m_timerValue(nullptr),
		m_restedValue(nullptr),
		m_timer(nullptr),
		m_rested(nullptr),
		m_startButton(nullptr),
		m_stopButton(nullptr),
		m_parent((wxFrameBase*)_parent)
	{
		CreateControls();
	}

	void MainPanel::OnStartButtonPressed(wxCommandEvent& _event)
	{
		m_parent->SetStatusText("Eyes Protection Reminder is still running...", 1);

		m_startButton->Disable();
		m_stopButton->Enable();

		m_rested->Stop();
		m_timer->Start(1000);

		s_timer_time_remaining = Config::GetInstance()->GetTimeRemaining();

		_event.Skip();
	}

	void MainPanel::OnStopButtonPressed(wxCommandEvent& _event)
	{
		m_parent->SetStatusText("Eyes Protection Reminder was stopped!", 1);

		m_startButton->Enable();
		m_stopButton->Disable();

		m_rested->Stop();
		m_timer->Stop();

		ResetTimer();

		_event.Skip();
	}

	void MainPanel::OnTimerElapsed(wxTimerEvent& _event)
	{
		if (--s_timer_time_remaining < 0)
		{
			// TODO: Show the notification

			// Start rested time
			m_timer->Stop();
			m_rested->Start(1000);

			s_timer_time_remaining = Config::GetInstance()->GetTimeRemaining();
			s_timer_rested_remaining = Config::GetInstance()->GetRestedRemaining();
		}

		m_timerValue->SetLabel(wxString::Format(
			"%s%d:%s%d",
			s_timer_time_remaining / 60 < 10 ? "0" : "",
			s_timer_time_remaining / 60,
			s_timer_time_remaining % 60 < 10 ? "0" : "",
			s_timer_time_remaining % 60
		));
	}

	void MainPanel::OnRestedElapsed(wxTimerEvent& _event)
	{
		if (--s_timer_rested_remaining < 0)
		{
			// Re-start the timer
			m_rested->Stop();
			m_timer->Start(1000);

			s_timer_time_remaining = Config::GetInstance()->GetTimeRemaining();
			s_timer_rested_remaining = Config::GetInstance()->GetRestedRemaining();
		}

		m_restedValue->SetLabel(wxString::Format(
			"%s%d:%s%d",
			s_timer_rested_remaining / 60 < 10 ? "0" : "",
			s_timer_rested_remaining / 60,
			s_timer_rested_remaining % 60 < 10 ? "0" : "",
			s_timer_rested_remaining % 60
		));
	}

	void MainPanel::CreateControls()
	{
		// Create label to show the value of timer
		m_timerValue = new wxStaticText(this, wxID_ANY, "");
		m_timerValue->SetFont(wxFont(90, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false));
		m_timerValue->SetToolTip("To show the timer...");

		// Create label to show the value of rested
		m_restedValue = new wxStaticText(this, wxID_ANY, "");
		m_restedValue->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false));
		m_restedValue->SetToolTip("To show the rested time...");

		ResetTimer();

		// Create start button
		m_startButton = new wxButton(this, EPR_Button_Start, "&Start");
		m_startButton->SetToolTip("To start the timer...");

		// Create stop button
		m_stopButton = new wxButton(this, EPR_Button_Stop, "&Stop");
		m_stopButton->SetToolTip("To stop the timer...");
		m_stopButton->Disable();

		// Create static line
		wxStaticLine* _staticLine = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxSize(455, 1), wxLI_HORIZONTAL);

		// Create flags
		wxSizerFlags _flags = wxSizerFlags().Border().Center();

		// Create bottom sizer
		wxSizer* _bottomSizer = new wxBoxSizer(wxHORIZONTAL);
		_bottomSizer->Add(m_startButton, 1, wxEXPAND | wxALL, 15);
		_bottomSizer->Add(m_stopButton, 1, wxEXPAND | wxALL, 15);

		// Create main sizer
		wxSizer* _mainSizer = new wxBoxSizer(wxVERTICAL);
		_mainSizer->Add(m_timerValue, _flags);
		_mainSizer->Add(m_restedValue, _flags);
		_mainSizer->Add(_staticLine, _flags);
		_mainSizer->Add(_bottomSizer, 1, wxEXPAND | wxALL);

		SetSizer(_mainSizer);
		Layout();

		// Create timer and rested
		m_timer = new wxTimer();
		m_rested = new wxTimer();

		m_timer->Bind(wxEVT_TIMER, &EPR::MainPanel::OnTimerElapsed, this);
		m_rested->Bind(wxEVT_TIMER, &EPR::MainPanel::OnRestedElapsed, this);
	}

	void MainPanel::ResetTimer()
	{
		s_timer_time_remaining = Config::GetInstance()->GetTimeRemaining();
		s_timer_rested_remaining = Config::GetInstance()->GetRestedRemaining();

		m_timerValue->SetLabel(wxString::Format(
			"%s%d:%s%d",
			s_timer_time_remaining / 60 < 10 ? "0" : "",
			s_timer_time_remaining / 60,
			s_timer_time_remaining % 60 < 10 ? "0" : "",
			s_timer_time_remaining % 60
		));

		m_restedValue->SetLabel(wxString::Format(
			"%s%d:%s%d",
			s_timer_rested_remaining / 60 < 10 ? "0" : "",
			s_timer_rested_remaining / 60,
			s_timer_rested_remaining % 60 < 10 ? "0" : "",
			s_timer_rested_remaining % 60
		));
	}
}