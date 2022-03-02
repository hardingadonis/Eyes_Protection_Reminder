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

import os
import sys
import schedule
import webbrowser
import time

import threading
from app import stray

from pathlib import Path
from tkinter import Tk, Canvas, Entry, Text, Button, PhotoImage

from win10toast import ToastNotifier

OUTPUT_PATH = Path(__file__).parent
ASSETS_PATH = OUTPUT_PATH / Path("./assets")

g_window = Tk()
is_start_reminder = False

def relative_to_assets(path: str) -> Path:
    return ASSETS_PATH / Path(path)

def create_main_ui():
    icon = PhotoImage(file = relative_to_assets("icon.png"))
    g_window.iconphoto(False, icon)

    g_window.title("Eyes Protection Reminder")
    g_window.geometry("400x323")
    g_window.configure(bg = "#3E3E42")

    canvas = Canvas(g_window, bg = "#3E3E42", height = 323, width = 400, bd = 0, highlightthickness = 0, relief = "ridge")

    canvas.place(x = 0, y = 0)
    button_image_1 = PhotoImage(file = relative_to_assets("button_1.png"))
    button_1 = Button(image = button_image_1,borderwidth = 0, highlightthickness = 0, command = lambda: (g_window.destroy(), is_button_1_clicked()), relief = "flat")
    button_1.place(x = 131.0, y = 201.0, width = 138.0, height = 35.0)

    button_image_2 = PhotoImage(file = relative_to_assets("button_2.png"))
    button_2 = Button(image = button_image_2, borderwidth = 0, highlightthickness = 0, command = lambda: webbrowser.open("https://github.com/hardingadonis/Eyes_Protection_Reminder"), relief = "flat")
    button_2.place(x = 131.0, y = 252.0, width = 138.0, height = 35.0)

    image_image_1 = PhotoImage(file = relative_to_assets("image_1.png"))
    image_1 = canvas.create_image(199.0, 61.0, image = image_image_1)

    image_image_2 = PhotoImage(file = relative_to_assets("image_2.png"))
    image_2 = canvas.create_image(233.0, 38.0, image = image_image_2)

    image_image_3 = PhotoImage(file = relative_to_assets("image_3.png"))
    image_3 = canvas.create_image(60.0, 62.0, image = image_image_3)

    image_image_4 = PhotoImage(file = relative_to_assets("image_4.png"))
    image_4 = canvas.create_image(155.0, 69.0, image = image_image_4)

    image_image_5 = PhotoImage(file = relative_to_assets("image_5.png"))
    image_5 = canvas.create_image(199.0, 133.0, image = image_image_5)

    image_image_6 = PhotoImage(file = relative_to_assets("image_6.png"))
    image_6 = canvas.create_image(199.0, 154.0, image = image_image_6)

    g_window.resizable(False, False)
    g_window.mainloop()

def is_button_1_clicked():
    global is_start_reminder
    is_start_reminder = True

def notification():
    toaster = ToastNotifier()
    toaster.show_toast("Eyes Protection Reminder", "Time to take a rest my dear ❤ Drop your glasses, look around.. Is there anything make you interesting?", icon_path = relative_to_assets("icon_white.ico"), duration = 30)

is_quit = False
def start_reminder():
    while True and not is_quit: 
        schedule.run_pending()
        time.sleep(1)

def exit_program(icon, item):
    icon.stop()

def on_quit(icon):
    global is_quit
    is_quit = True

    icon.visible = False
    icon.stop()

waiting_time_in_seconds = 1200
def on_change_mode(seconds = 1200):
    def func():
       global waiting_time_in_seconds
       waiting_time_in_seconds = seconds 
    return func

is_turn_off = False
job = ''
def toggle_job(icon, item, state=None):
    global is_turn_off
    global job

    if state != None: 
        is_turn_off = state
    else:
        is_turn_off = not is_turn_off

    if is_turn_off: 
        if job != '': schedule.cancel_job(job)
    else: 
        job = schedule.every(waiting_time_in_seconds).seconds.do(notification)

def get_waiting_time():
    return waiting_time_in_seconds
        
def get_turn_off_state():
    return is_turn_off
        

if __name__ == "__main__":
    create_main_ui()

    if is_start_reminder == True:
        threading.Thread(target=lambda item=None: stray(on_quit, on_change_mode, get_waiting_time, toggle_job, get_turn_off_state)).start()
        toggle_job(None, None, False)
        start_reminder()