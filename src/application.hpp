#pragma once

#include <wx/wx.h>
#include <wx/snglinst.h>

class Application : public wxApp
{
public:
	bool OnInit() override;

	int OnExit() override;

private:
	wxSingleInstanceChecker*	m_checker;
};