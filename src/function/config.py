
from utils.stateFactory import stateFactory

# Every <timing> seconds, the app will notify user to relax
get_timing, set_timing = stateFactory(20, 'timing')

# duration of the notification on second
get_duration, set_duration = stateFactory(10, 'duration')

# Notify content
get_content, set_content = stateFactory('Time to take a rest my dear ❤ Drop your glasses, look around.. Is there anything make you interesting?', 'content')

# App mode
# Available mode: normal, hardcore
get_mode, set_mode = stateFactory('normal', 'mode')

# Other config ....