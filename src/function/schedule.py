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


thread = None

is_quit = False

# notify user to relax every period of time
def reminder():
    while True and not is_quit: 
        schedule.run_pending()
        time.sleep(1)

# Init schedule for app
# create new thread to run schedule
def init_schedule():
   global thread
   thread = threading.Thread(target=reminder)
   print('Init thread successfully')

# Start schedule for app
# start or restart schedule in case user pause it
def start_schedule():
   print('Starting schedule thread')
   thread.start()

def pause_schedule():
   pass

# terminate threading and quit
def quit_schedule():
   pass