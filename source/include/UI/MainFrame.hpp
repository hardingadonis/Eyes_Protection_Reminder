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
#include <UI/MainPanel.hpp>
#include <UI/TaskBarIcon.hpp>

namespace EPR
{
	class MainFrame : public wxFrame
	{
	public:
		MainFrame(const wxString& _title, const wxSize& _size);
		~MainFrame();

		void OnMenuHide(wxCommandEvent& _event);
		void OnMenuQuit(wxCommandEvent& _event);
		void OnMenuSettings(wxCommandEvent& _event);
		void OnMenuAbout(wxCommandEvent& _event);

		void OnCloseWindow(wxCloseEvent& _event);

	private:
		void CreateControls();

	private:
		MainPanel*		m_mainPanel;
		TaskBarIcon*	m_taskBarIcon;

	public:
		wxDECLARE_EVENT_TABLE();
	};
}