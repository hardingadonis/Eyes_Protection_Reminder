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

from utils.stateFactory import stateFactory

get_is_quit, set_is_quit = stateFactory(False)
get_is_pause, set_is_pause = stateFactory(False)

# Every <timing> seconds, the app will notify user to relax
get_timing, set_timing = stateFactory(20 * 60, "timing")

# duration of the notification on second
get_duration, set_duration = stateFactory(30, "duration")

# Notify content
get_content, set_content = stateFactory("Time to take a rest my dear ❤ Drop your glasses, look around.. Is there anything make you interesting?", "content")

# App mode
# Available mode: normal, hardcore
get_mode, set_mode = stateFactory("normal", "mode")

# Other config ....