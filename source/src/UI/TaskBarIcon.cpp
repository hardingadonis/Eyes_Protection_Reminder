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

#include <UI/TaskBarIcon.hpp>

namespace EPR
{
	enum EPR_Menu
	{
		EPR_Menu_Restore	= 12001,
		EPR_Menu_Source		= 12002,
		EPR_Menu_Exit		= 12003
	};

	wxBEGIN_EVENT_TABLE(TaskBarIcon, wxTaskBarIcon)
		EVT_MENU(EPR_Menu_Restore, TaskBarIcon::OnMenuRestore)
		EVT_MENU(EPR_Menu_Source, TaskBarIcon::OnMenuSource)
		EVT_MENU(EPR_Menu_Exit, TaskBarIcon::OnMenuExit)
		EVT_TASKBAR_LEFT_DCLICK(TaskBarIcon::OnLeftButtonDClick)
	wxEND_EVENT_TABLE()

	TaskBarIcon::TaskBarIcon(wxWindow* _parent, wxTaskBarIconType _iconType) :
		wxTaskBarIcon(_iconType),
		m_parent((wxFrameBase*)_parent)
	{
	}

	void TaskBarIcon::OnMenuRestore(wxCommandEvent& _event)
	{
		m_parent->Show();

		_event.Skip();
	}

	void TaskBarIcon::OnMenuSource(wxCommandEvent& _event)
	{
		wxLaunchDefaultBrowser("https://github.com/hardingadonis/Eyes_Protection_Reminder");

		_event.Skip();
	}

	void TaskBarIcon::OnMenuExit(wxCommandEvent& _event)
	{
		m_parent->Close(true);

		_event.Skip();
	}

	void TaskBarIcon::OnLeftButtonDClick(wxTaskBarIconEvent& _event)
	{
		m_parent->Show();

		_event.Skip();
	}

	wxMenu* TaskBarIcon::CreatePopupMenu()
	{
		wxMenu* _menu = new wxMenu();

		_menu->Append(EPR_Menu_Restore, "&Restore Main Window");
		_menu->AppendSeparator();
		_menu->Append(EPR_Menu_Source, "&Source Code");
		_menu->AppendSeparator();
		_menu->Append(EPR_Menu_Exit, "&Exit");

		return _menu;
	}
}