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

#include <UI/SettingsDialog.hpp>
#include <Utils/Config.hpp>

namespace EPR
{
    enum EPR_Button
    {
        EPR_Button_Save = 13001
    };

    wxBEGIN_EVENT_TABLE(SettingsDialog, wxDialog)
        EVT_BUTTON(EPR_Button_Save, SettingsDialog::OnSaveButtonPressed)
    wxEND_EVENT_TABLE()

    SettingsDialog::SettingsDialog(wxWindow* _parent) :
        wxDialog(_parent, wxID_ANY, "Eyes Protection Remimder - Settings")
    {
        Center();
        CreateControls();
        SetClientSize(wxSize(500, 250));
    }

    void SettingsDialog::OnSaveButtonPressed(wxCommandEvent& _event)
    {
        Config::GetInstance()->SetTimeRemaining(m_timeRemaining->GetValue());
        Config::GetInstance()->SetRestedRemaining(m_restedRemaining->GetValue());
        Config::GetInstance()->SetTimeNotification(m_timeNotification->GetValue());
        Config::GetInstance()->SetStringNotification(m_stringNotification->GetValue());
        Config::GetInstance()->SetStartupWithWindows(m_startupWithWindows->GetValue());

        Config::GetInstance()->Save();

        Destroy();
    }

    void SettingsDialog::CreateControls()
    {
        wxStaticText* _second_1 = new wxStaticText(this, wxID_ANY, "   seconds");
        _second_1->SetMinSize(wxSize(70, _second_1->GetMinSize().y));

        wxStaticText* _second_2 = new wxStaticText(this, wxID_ANY, "   seconds");
        _second_2->SetMinSize(wxSize(70, _second_2->GetMinSize().y));

        wxStaticText* _second_3 = new wxStaticText(this, wxID_ANY, "   seconds");
        _second_3->SetMinSize(wxSize(70, _second_3->GetMinSize().y));

        // Time Remaining
        m_timeRemaining = new wxSpinCtrl(this, wxID_ANY);
        m_timeRemaining->SetMin(1200);
        m_timeRemaining->SetMax(3600);
        m_timeRemaining->SetValue(Config::GetInstance()->GetTimeRemaining());
        m_timeRemaining->SetToolTip("The time remaining must be between 20 minutes to 60 minutes (1200 seconds to 3600 seconds)");
        wxStaticText* _timeRemainingText = new wxStaticText(this, wxID_ANY, "Time Remaining:");
        _timeRemainingText->SetMinSize(wxSize(150, _timeRemainingText->GetMinSize().y));

        // Rested Remaining
        m_restedRemaining = new wxSpinCtrl(this, wxID_ANY);
        m_restedRemaining->SetMin(20);
        m_restedRemaining->SetMax(300);
        m_restedRemaining->SetValue(Config::GetInstance()->GetRestedRemaining());
        m_restedRemaining->SetToolTip("The rested remaining must be between 20 seconds to 5 minutes (20 seconds to 300 seconds)");
        wxStaticText* _restedRemainingText = new wxStaticText(this, wxID_ANY, "Rested Remaining:");
        _restedRemainingText->SetMinSize(wxSize(150, _restedRemainingText->GetMinSize().y));

        // Time Notification
        m_timeNotification = new wxSpinCtrl(this, wxID_ANY);
        m_timeNotification->SetMin(10);
        m_timeNotification->SetMax(60);
        m_timeNotification->SetValue(Config::GetInstance()->GetTimeNotification());
        m_timeNotification->SetToolTip("The time notification must be between 10 seconds to 60 seconds");
        wxStaticText* _timeNotificationText = new wxStaticText(this, wxID_ANY, "Time Notification:");
        _timeNotificationText->SetMinSize(wxSize(150, _timeNotificationText->GetMinSize().y));

        // String Notification
        m_stringNotification = new wxTextCtrl(this, wxID_ANY, Config::GetInstance()->GetStringNotification());
        m_stringNotification->SetToolTip("Change the reminder content for yourself");
        wxStaticText* _stringNotificationText = new wxStaticText(this, wxID_ANY, "String Notification:");
        _stringNotificationText->SetMinSize(wxSize(150, _stringNotificationText->GetMinSize().y));

        // Startup With Windows
        m_startupWithWindows = new wxCheckBox(this, wxID_ANY, wxEmptyString);
        m_startupWithWindows->SetValue(Config::GetInstance()->GetStartupWithWindows());
        m_startupWithWindows->SetToolTip("This tool will be started with Windows if this option is turned on");
        wxStaticText* _startupWithWindowsText = new wxStaticText(this, wxID_ANY, "Startup With Windows:");
        _startupWithWindowsText->SetMinSize(wxSize(150, _startupWithWindowsText->GetMinSize().y));

        // Create static line
        wxStaticLine* _staticLine = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxSize(500, 1), wxLI_HORIZONTAL);

        // Save Button
        wxButton* _saveButton = new wxButton(this, EPR_Button_Save, "Save");

        // Setup sizers
        wxSizer* _timeRemainingSizer = new wxBoxSizer(wxHORIZONTAL);
        _timeRemainingSizer->Add(_timeRemainingText, 0, wxALIGN_CENTER, 5);
        _timeRemainingSizer->Add(m_timeRemaining, 1, wxEXPAND | wxALL, 5);
        _timeRemainingSizer->Add(_second_1, 0, wxALIGN_CENTER, 5);

        wxSizer* _restedRemainingSizer = new wxBoxSizer(wxHORIZONTAL);
        _restedRemainingSizer->Add(_restedRemainingText, 0, wxALIGN_CENTER, 5);
        _restedRemainingSizer->Add(m_restedRemaining, 1, wxEXPAND | wxALL, 5);
        _restedRemainingSizer->Add(_second_2, 0, wxALIGN_CENTER, 5);

        wxSizer* _timeNotificationSizer = new wxBoxSizer(wxHORIZONTAL);
        _timeNotificationSizer->Add(_timeNotificationText, 0, wxALIGN_CENTER, 5);
        _timeNotificationSizer->Add(m_timeNotification, 1, wxEXPAND | wxALL, 5);
        _timeNotificationSizer->Add(_second_3, 0, wxALIGN_CENTER, 5);

        wxSizer* _stringNotificationSizer = new wxBoxSizer(wxHORIZONTAL);
        _stringNotificationSizer->Add(_stringNotificationText, 0, wxALIGN_CENTER, 5);
        _stringNotificationSizer->Add(m_stringNotification, 1, wxEXPAND | wxALL, 5);
        
        wxSizer* _startupWithWindowsSizer = new wxBoxSizer(wxHORIZONTAL);
        _startupWithWindowsSizer->Add(_startupWithWindowsText, 0, wxALIGN_CENTER, 5);
        _startupWithWindowsSizer->Add(m_startupWithWindows, 1, wxEXPAND | wxALL, 5);

        wxSizer* _mainSizer = new wxBoxSizer(wxVERTICAL);
        _mainSizer->Add(_timeRemainingSizer, 1, wxEXPAND | wxALL, 5);
        _mainSizer->Add(_restedRemainingSizer, 1, wxEXPAND | wxALL, 5);
        _mainSizer->Add(_timeNotificationSizer, 1, wxEXPAND | wxALL, 5);
        _mainSizer->Add(_stringNotificationSizer, 1, wxEXPAND | wxALL, 5);
        _mainSizer->Add(_startupWithWindowsSizer, 1, wxEXPAND | wxALL, 5);
        _mainSizer->Add(_staticLine, wxSizerFlags().Border().Center());
        _mainSizer->Add(_saveButton, wxSizerFlags().Border().Center());

        SetSizer(_mainSizer);
        Layout();
    }
}