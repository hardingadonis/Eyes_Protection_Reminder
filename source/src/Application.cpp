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

#include <wx/wx.h>
#include <wx/taskbar.h>
#include <Application.hpp>

namespace EPR
{
    bool Application::OnInit()
    {
        m_instanceChecker = new wxSingleInstanceChecker();

        if (m_instanceChecker->IsAnotherRunning())
        {
            wxLogError(_("Another program instance is already running, aborting."));

            delete m_instanceChecker;
            m_instanceChecker = nullptr;

            return false;
        }

        if (!wxTaskBarIcon::IsAvailable())
        {
            wxMessageBox(
                "Sorry! This tool can not run on your device.",
                "Eyes Protection Reminder",
                wxOK | wxICON_ERROR
            );

            return false;
        }

        m_mainFrame = new MainFrame("Eyes Protection Remimder - v4.1.0", wxSize(500, 350));

        if (m_mainFrame == nullptr)
        {
            return false;
        }

        m_mainFrame->Show();
        
        return true;
    }

    int Application::OnExit()
    {
        if (m_instanceChecker != nullptr)
        {
            delete m_instanceChecker;
            m_instanceChecker = nullptr;
        }

        return 0;
    }

    wxIMPLEMENT_APP(Application);
}