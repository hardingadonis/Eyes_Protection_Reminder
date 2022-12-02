#pragma once

#include <wx/wx.h>
#include <wx/snglinst.h>

namespace EPR
{
    class Application : public wxApp
    {
    public:
        bool OnInit() override;

        int OnExit() override;

    private:
        wxSingleInstanceChecker*    m_instanceChecker;
    };
}