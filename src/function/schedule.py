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
import threading
import time

from win10toast import ToastNotifier

from utils.stateFactory import stateFactory
from utils.relativeLink import relative_to_assets

thread = None
job = None

get_is_quit, set_is_quit = stateFactory(False)

from function.config import get_timing, get_duration

# prevent the app from terminating
def loop():
    while True and not get_is_quit(): 
        schedule.run_pending()
        time.sleep(1)

# Init schedule for app
# create new thread to run schedule
def init_schedule():
   global thread
   thread = threading.Thread(target=loop)
   print('Init thread successfully')

# Start schedule for app
# start or restart schedule in case user pause it
def start_schedule():
   global job
   global thread
   if thread == None:
      thread = threading.Thread(target=loop)
      print('Init thread successfully')
      thread.start()
      print('Starting schedule thread')

   job = schedule.every(get_timing()).seconds.do(notification)

def pause_schedule():
   if job != None: schedule.cancel_job(job)

# terminate threading and quit
def quit_schedule():
   global job
   if job != None: schedule.cancel_job(job)
   set_is_quit(True)

def notification():
   toaster = ToastNotifier()
   toaster.show_toast("Eyes Protection Reminder", "Time to take a rest my dear ❤ Drop your glasses, look around.. Is there anything make you interesting?", icon_path=relative_to_assets('../../../assets/icon_white.ico'), duration = get_duration())
