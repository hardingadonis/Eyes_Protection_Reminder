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

from pathlib import Path

OUTPUT_PATH = Path(__file__).parent
ASSETS_PATH = OUTPUT_PATH / Path("./assets")

def relative_to_assets(path: str) -> Path:
    return ASSETS_PATH / Path(path)

def on_quit(icon):
    icon.visible = False
    icon.stop()

state = False

def open_about_us(icon, item):
    global state
    state = not item.checked
    print("click")
    url = 'https://github.com/hardingadonis/Eyes_Protection_Reminder'
    chrome_path = 'C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe'
    webbrowser.register('chrome', None, webbrowser.BackgroundBrowser(chrome_path))
    webbrowser.get('chrome').open(url)

def stray(on_quit, on_change_mode, get_waiting_time, toggle_job, get_turn_off_state):
    image = Image.open(relative_to_assets("icon.png"))

    menu = Menu(
        item('Change relax time', Menu(
            item('10 minutes', on_change_mode(600), lambda item: bool(600 == get_waiting_time())),
            item('20 minutes', on_change_mode(1200), lambda item: bool(1200 == get_waiting_time())),
            item('30 minutes', on_change_mode(1800), lambda item: bool(1800 == get_waiting_time())),
            item('60 minutes', on_change_mode(3600), lambda item: bool(3600 == get_waiting_time())),
        )),
        item('Hardcore mode (No relaxing)', lambda icon, item: toggle_job(icon, item, None), lambda item: get_turn_off_state()),
        item('About us', open_about_us),
        item('Quit', on_quit)
        )

    icon = pystray.Icon("Resolution Switcher", image, "Resolution Switcher", menu)
    icon.run()