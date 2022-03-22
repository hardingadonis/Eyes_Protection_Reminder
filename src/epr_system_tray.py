"""

MIT License

Copyright (c) 2022 Harding Adonis, hoanghy0112, AlexPhoenix45
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

"""
from pystray import MenuItem, Menu
import pystray

from PIL import Image

import threading
import webbrowser

import epr_language as Language
import epr_config as Config

def _chageTimeReminder_5():
    Config.SetConfig("time_reminder", "5")

def _chageTimeReminder_10():
    Config.SetConfig("time_reminder", "10")

def _chageTimeReminder_15():
    Config.SetConfig("time_reminder", "15")

def _chageTimeReminder_20():
    Config.SetConfig("time_reminder", "20")

def _chageTimeReminder_25():
    Config.SetConfig("time_reminder", "25")

def _chageTimeReminder_30():
    Config.SetConfig("time_reminder", "30")

def _chageTimeReminder_35():
    Config.SetConfig("time_reminder", "35")

def _chageTimeReminder_40():
    Config.SetConfig("time_reminder", "40")

def _chageTimeReminder_45():
    Config.SetConfig("time_reminder", "45")

def _chageTimeReminder_50():
    Config.SetConfig("time_reminder", "50")

def _chageTimeReminder_55():
    Config.SetConfig("time_reminder", "55")

def _chageTimeReminder_60():
    Config.SetConfig("time_reminder", "60")


def _changeHardcodeMode():
    if Config.GetConfig("hardcode_mode") == "true":
        Config.SetConfig("hardcode_mode", "false")
    elif Config.GetConfig("hardcode_mode") == "false":
        Config.SetConfig("hardcode_mode", "true")

def _changeLanguage():
    if Config.GetConfig("language") == "en":
        Config.SetConfig("language", "vi")
    elif Config.GetConfig("language") == "vi":
        Config.SetConfig("language", "en")

def _openSourceCode():
    url = "https://github.com/hardingadonis/Eyes_Protection_Reminder"
    webbrowser.open(url)

def _onExit(system_tray):
    system_tray.visible = False
    system_tray.stop()

def _startSystemTray():
    icon = Image.open("assets/icon.ico")
    
    menu = Menu(
        MenuItem(Language.GetLanguage("EPR_01"), Menu(
            MenuItem(Language.GetLanguage("EPR_02"), _chageTimeReminder_5, lambda _isChecked: bool(Config.GetConfig("time_reminder") == "5")),
            MenuItem(Language.GetLanguage("EPR_03"), _chageTimeReminder_10, lambda _isChecked: bool(Config.GetConfig("time_reminder") == "10")),
            MenuItem(Language.GetLanguage("EPR_04"), _chageTimeReminder_15, lambda _isChecked: bool(Config.GetConfig("time_reminder") == "15")),
            MenuItem(Language.GetLanguage("EPR_05"), _chageTimeReminder_20, lambda _isChecked: bool(Config.GetConfig("time_reminder") == "20")),
            MenuItem(Language.GetLanguage("EPR_06"), _chageTimeReminder_25, lambda _isChecked: bool(Config.GetConfig("time_reminder") == "25")),
            MenuItem(Language.GetLanguage("EPR_07"), _chageTimeReminder_30, lambda _isChecked: bool(Config.GetConfig("time_reminder") == "30")),
            MenuItem(Language.GetLanguage("EPR_08"), _chageTimeReminder_35, lambda _isChecked: bool(Config.GetConfig("time_reminder") == "35")),
            MenuItem(Language.GetLanguage("EPR_09"), _chageTimeReminder_40, lambda _isChecked: bool(Config.GetConfig("time_reminder") == "40")),
            MenuItem(Language.GetLanguage("EPR_10"), _chageTimeReminder_45, lambda _isChecked: bool(Config.GetConfig("time_reminder") == "45")),
            MenuItem(Language.GetLanguage("EPR_11"), _chageTimeReminder_50, lambda _isChecked: bool(Config.GetConfig("time_reminder") == "50")),
            MenuItem(Language.GetLanguage("EPR_12"), _chageTimeReminder_55, lambda _isChecked: bool(Config.GetConfig("time_reminder") == "55")),
            MenuItem(Language.GetLanguage("EPR_13"), _chageTimeReminder_60, lambda _isChecked: bool(Config.GetConfig("time_reminder") == "60"))
        )),
        MenuItem(Language.GetLanguage("EPR_14"), _changeHardcodeMode, lambda _isChecked: bool(Config.GetConfig("hardcode_mode") == "true")),
        MenuItem(Language.GetLanguage("EPR_15"), Menu(
            MenuItem(Language.GetLanguage("EPR_16"), _changeLanguage, lambda _isChecked: bool(Config.GetConfig("language") == "en")),
            MenuItem(Language.GetLanguage("EPR_17"), _changeLanguage, lambda _isChecked: bool(Config.GetConfig("language") == "vi"))
        )),
        MenuItem(Language.GetLanguage("EPR_18"), _openSourceCode),
        MenuItem(Language.GetLanguage("EPR_19"), _onExit)
    )

    system_tray = pystray.Icon("Eyes Protection Reminder", icon, "Eyes Protection Reminder", menu)
    system_tray.run()

StartSystemTray = _startSystemTray