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

import pystray
from PIL import Image
from pystray import MenuItem as item, Menu
import webbrowser
from utils.relativeLink import relative_to_assets
import threading

from function.config import get_is_pause, set_is_pause, set_is_quit, get_timing, set_mode, get_mode
from function.schedule import quit_schedule, pause_schedule, start_schedule, change_timing

state = False

def on_quit(icon):
    set_is_quit(True)
    quit_schedule()
    icon.visible = False
    icon.stop()

def open_source_code(icon, item):
    url = "https://github.com/hardingadonis/Eyes_Protection_Reminder"
    webbrowser.open(url)

def change_mode():
    if get_mode() == "hardcore": 
        set_mode("normal")
    else:
        set_mode("hardcore")

def change_is_pause():
    if get_is_pause() == False:
        pause_schedule()
    else:
        start_schedule()

def start_tray():
    image = Image.open(relative_to_assets("icon.ico"))
        
    menu = Menu(
        item("Change relax time", Menu(
            item("10 minutes", lambda item: change_timing(600), lambda item: bool(600 == get_timing())),
            item("20 minutes", lambda item: change_timing(1200), lambda item: bool(1200 == get_timing())),
            item("30 minutes", lambda item: change_timing(1800), lambda item: bool(1800 == get_timing())),
            item("60 minutes", lambda item: change_timing(3600), lambda item: bool(3600 == get_timing())),
        )),
        item("Hardcore mode (No relaxing)", change_mode, lambda item: bool(get_mode() == "hardcore")),
        item("Source Code", open_source_code),
        item("Quit", on_quit)
        )

    icon = pystray.Icon("Eyes Protection Reminder", image, "Eyes Protection Reminder", menu)
    threading.Thread(target=lambda item=None: icon.run()).start()
   