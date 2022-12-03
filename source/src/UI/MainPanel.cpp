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

#include <wx/statline.h>
#include <UI/MainPanel.hpp>

namespace EPR
{
	// IDs for the controls
	enum
	{
		EPR_Button_Start	= 11001,
		EPR_Button_Stop		= 11002
	};

	wxBEGIN_EVENT_TABLE(MainPanel, wxPanel)
	wxEND_EVENT_TABLE()

	MainPanel::MainPanel(wxWindow* _parent) :
		wxPanel(_parent, wxID_ANY),
		m_timerValue(nullptr),
		m_startButton(nullptr),
		m_stopButton(nullptr)
	{
		CreateControls();
	}

	void MainPanel::CreateControls()
	{
		// Create label to show the value of timer
		m_timerValue = new wxStaticText(this, wxID_ANY, "20:00");
		m_timerValue->SetFont(wxFont(90, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false));
		m_timerValue->SetToolTip("To show the timer...");

		// Create start button
		m_startButton = new wxButton(this, EPR_Button_Start, "&Start");
		m_startButton->SetToolTip("To start the timer...");

		// Create stop button
		m_stopButton = new wxButton(this, EPR_Button_Stop, "&Stop");
		m_stopButton->SetToolTip("To stop the timer...");

		// Create static line
		wxStaticLine* _staticLine = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxSize(450, 1), wxLI_HORIZONTAL);

		// Create flags
		wxSizerFlags _flags = wxSizerFlags().Border().Center();

		// Create bottom sizer
		wxSizer* _bottomSizer = new wxBoxSizer(wxHORIZONTAL);
		_bottomSizer->Add(m_startButton, _flags);
		_bottomSizer->Add(m_stopButton, _flags);

		// Create main sizer
		wxSizer* _mainSizer = new wxBoxSizer(wxVERTICAL);
		_mainSizer->Add(m_timerValue, _flags);
		_mainSizer->Add(_staticLine, _flags);
		_mainSizer->Add(_bottomSizer, _flags);

		SetSizer(_mainSizer);
	}
}