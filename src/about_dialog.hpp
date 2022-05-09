#pragma once

#include <wx/wx.h>

class AboutDialog : public wxDialog
{
public:
    AboutDialog(wxWindow* parent, wxWindowID id, const wxString& title,const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize);
    virtual ~AboutDialog() = default;

    void OnButtonOKPressed(wxCommandEvent& event);

private:
    wxButton*       m_buttonOK;

public:
    wxDECLARE_EVENT_TABLE();
};