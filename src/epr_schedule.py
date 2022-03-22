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

import schedule
import time
import threading

from win10toast import ToastNotifier

import epr_language as Language
import epr_config as Config

def _getTime() -> int:
    if Config.GetConfig("time_reminder") == "5":
        return 5
    if Config.GetConfig("time_reminder") == "10":
        return 10
    if Config.GetConfig("time_reminder") == "15":
        return 15
    if Config.GetConfig("time_reminder") == "20":
        return 20
    if Config.GetConfig("time_reminder") == "25":
        return 25
    if Config.GetConfig("time_reminder") == "30":
        return 30
    if Config.GetConfig("time_reminder") == "35":
        return 35
    if Config.GetConfig("time_reminder") == "40":
        return 40
    if Config.GetConfig("time_reminder") == "45":
        return 45
    if Config.GetConfig("time_reminder") == "50":
        return 50
    if Config.GetConfig("time_reminder") == "55":
        return 55
    if Config.GetConfig("time_reminder") == "60":
        return 60

def _notification():
    toaster = ToastNotifier()
    toaster.show_toast("Eyes Protection Reminder", msg = Language.GetLanguage("EPR_20"), icon_path = "assets/icon.ico", duration = 5)

_notification = _notification