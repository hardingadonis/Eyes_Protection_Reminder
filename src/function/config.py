
from utils.stateFactory import stateFactory

# Every <timing> minutes, the app will notify user to relax
get_timing, set_timing = stateFactory(2, 'timing')

# duration of the notification
get_duration, set_duration = stateFactory(5, 'duration')

# Notify content
get_content, set_content = stateFactory('Time to take a rest my dear ❤ Drop your glasses, look around.. Is there anything make you interesting?', 'content')

# App mode
get_mode, set_mode = stateFactory('normal', 'mode')

# Other config ....