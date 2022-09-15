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

#include "application.hpp"
#include "main_frame.hpp"
#include <wx/wx.h>

bool Application::OnInit()
{
	m_checker = new wxSingleInstanceChecker;

	if (m_checker->IsAnotherRunning())
	{
		wxLogError(_("Another program instance is already running, aborting."));

		delete m_checker;
		m_checker = nullptr;

		return false;
	}


	MainFrame* main_frame = new MainFrame("Eyes Protection Reminder - v4.0.0", wxSize(600, 300));

	main_frame->Center();
	main_frame->Show();

	return true;
}

int Application::OnExit()
{
	delete m_checker;
	m_checker = nullptr;

	return 0;
}

wxIMPLEMENT_APP(Application);