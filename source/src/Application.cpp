#include <wx/wx.h>
#include <Application.hpp>

namespace EPR
{
    bool Application::OnInit()
    {
        if (m_instanceChecker == nullptr)
        {
            m_instanceChecker = new wxSingleInstanceChecker();
        }

        if (m_instanceChecker->IsAnotherRunning())
        {
            delete m_instanceChecker;
            m_instanceChecker = nullptr;

            return false;
        }

        return true;
    }

    int OnExit()
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