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

#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/fileconf.h>

#include <Utils/Config.hpp>

#include <Windows.h>

namespace EPR
{
	namespace Priv
	{
		static const int TIME_REMAINING				= 1200;
		static const int RESTED_REMAINING			= 20;
		static const int TIME_NOTIFICATION			= 30;
		static const wxString STRING_NOTIFICATION	= wxString::FromUTF8("Hey bro. Relax now!!!");
		static const bool STARTUP_WITH_WINDOWS		= false;

		static wxString PATH;
		static wxString FILE = "EPR_config.ini";

		void AddRegistry()
		{
			HKEY _hkey;
			LONG _key = RegOpenKeyExA(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\Currentversion\\Run", 0, KEY_WRITE, &_hkey);

			if (_key == ERROR_SUCCESS)
			{
				std::string _executablePath = wxStandardPaths::Get().GetExecutablePath().ToStdString();

				_key = RegSetValueExA(_hkey, "Eyes Protection Remimder", 0, REG_SZ, (BYTE*)_executablePath.c_str(), strlen(_executablePath.c_str()));
			}
		}

		void RemoveRegistry()
		{
			HKEY _hkey = HKEY_CURRENT_USER;

			RegOpenKeyA(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\Currentversion\\Run", &_hkey);

			RegDeleteValueA(_hkey, "Eyes Protection Remimder");

			RegCloseKey(_hkey);
		}
	}

	Config::Config() :
		m_timeRemaining(0),
		m_restedRemaining(0),
		m_timeNotification(0),
		m_startupWithWindows(0)
	{
		Priv::PATH = wxStandardPaths::Get().GetUserConfigDir() + wxFileName::GetPathSeparator() + "Eyes_Protection_Reminder" + wxFileName::GetPathSeparator();

		LoadConfigFromFile();
	}

	int Config::GetTimeRemaining() const
	{
		return m_timeRemaining;
	}

	int Config::GetRestedRemaining() const
	{
		return m_restedRemaining;
	}

	int Config::GetTimeNotification() const
	{
		return m_timeNotification;
	}

	wxString Config::GetStringNotification() const
	{
		return m_stringNotification;
	}

	bool Config::GetStartupWithWindows() const
	{
		return m_startupWithWindows;
	}

	void Config::SetTimeRemaining(int _timeRemaining)
	{
		// The time remaining must be between 20 minutes to 60 minutes
		if (_timeRemaining >= 1200 && _timeRemaining <= 3600)
		{
			m_timeRemaining = _timeRemaining;
		}
	}

	void Config::SetRestedRemaining(int _restedRemaining)
	{
		// The rested remaining must be between 20 seconds to 5 minutes
		if (_restedRemaining >= 20 && _restedRemaining <= 300)
		{
			m_restedRemaining = _restedRemaining;
		}
	}

	void Config::SetTimeNotification(int _timeNotification)
	{
		// The time notification must be between 10 seconds to 60 seconds
		if (_timeNotification >= 10 && _timeNotification <= 60)
		{
			m_timeNotification = _timeNotification;
		}
	}

	void Config::SetStringNotification(const wxString& _stringNotification)
	{
		if (!_stringNotification.IsEmpty())
		{
			m_stringNotification = _stringNotification;
		}
	}

	void Config::SetStartupWithWindows(bool _startupWithWindows)
	{
		if (!m_startupWithWindows && _startupWithWindows)
		{
			Priv::AddRegistry();
		}
		else if (m_startupWithWindows && !_startupWithWindows)
		{
			Priv::RemoveRegistry();
		}

		m_startupWithWindows = _startupWithWindows;
	}

	void Config::Save()
	{
		wxFileConfig* _config = new wxFileConfig("Eyes Protection Remimder", wxEmptyString, Priv::PATH + Priv::FILE);

		_config->SetPath("/UserData");
		_config->Write("TIME_REMAINING", m_timeRemaining);
		_config->Write("RESTED_REMAINING", m_restedRemaining);
		_config->Write("TIME_NOTIFICATION", m_timeNotification);
		_config->Write("STRING_NOTIFICATION", m_stringNotification);

		_config->SetPath("/System");
		_config->Write("STARTUP_WITH_WINDOWS", m_startupWithWindows);

		_config->Flush();

		// Delete this pointer
		delete _config;
		_config = nullptr;
	}

	void Config::LoadConfigFromFile()
	{
		// Check if _path is exists
		if (!wxFileName::DirExists(Priv::PATH))
		{
			// Create _path
			wxFileName::Mkdir(Priv::PATH);

			// Then, load default config
			LoadDefaultConfig();

			return;
		}

		// Check if _path + _fileName is exists
		if (!wxFileName::FileExists(Priv::PATH + Priv::FILE))
		{
			// Use the default config
			LoadDefaultConfig();

			return;
		}

		// If done, load config from file
		wxFileConfig* _config = new wxFileConfig("Eyes Protection Remimder", wxEmptyString, Priv::PATH + Priv::FILE);

		_config->SetPath("/UserData");
		_config->Read("TIME_REMAINING", &m_timeRemaining);
		_config->Read("RESTED_REMAINING", &m_restedRemaining);
		_config->Read("TIME_NOTIFICATION", &m_timeNotification);
		_config->Read("STRING_NOTIFICATION", &m_stringNotification);

		_config->SetPath("/System");
		_config->Read("STARTUP_WITH_WINDOWS", &m_startupWithWindows);

		// Delete this pointer
		delete _config;
		_config = nullptr;
	}

	void Config::LoadDefaultConfig()
	{
		m_timeRemaining			= Priv::TIME_REMAINING;
		m_restedRemaining		= Priv::RESTED_REMAINING;
		m_timeNotification		= Priv::TIME_NOTIFICATION;
		m_stringNotification	= Priv::STRING_NOTIFICATION;
		m_startupWithWindows	= Priv::STARTUP_WITH_WINDOWS;
	}
}