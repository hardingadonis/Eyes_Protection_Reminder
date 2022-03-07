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

def open_about_us(icon, item):
    url = 'https://github.com/hardingadonis/Eyes_Protection_Reminder'
    chrome_path = 'C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe'
    webbrowser.register('chrome', None, webbrowser.BackgroundBrowser(chrome_path))
    webbrowser.get('chrome').open(url)

def change_mode():
    if get_mode() == 'hardcore': 
        set_mode('normal')
    else:
        set_mode('hardcore')

def change_is_pause():
    if get_is_pause() == False:
        pause_schedule()
    else:
        start_schedule()

def start_tray():
    print(relative_to_assets("icon_white.ico"))
    image = Image.open(relative_to_assets("icon_white.ico"))
        
    menu = Menu(
        item('Change relax time', Menu(
            item('10 seconds', lambda item: change_timing(10), lambda item: bool(10 == get_timing())),
            item('20 minutes', lambda item: change_timing(1200), lambda item: bool(1200 == get_timing())),
            item('30 minutes', lambda item: change_timing(1800), lambda item: bool(1800 == get_timing())),
            item('60 minutes', lambda item: change_timing(3600), lambda item: bool(3600 == get_timing())),
        )),
        item('Pause', change_is_pause, lambda item=None: get_is_pause() == True),
        item('Hardcore mode (No relaxing)', change_mode, lambda item: bool(get_mode() == 'hardcore')),
        item('About us', open_about_us),
        item('Quit', on_quit)
        )

    icon = pystray.Icon("Eyes Protection Reminder", image, "Eyes Protection Reminder", menu)
    threading.Thread(target=lambda item=None: icon.run()).start()
   