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
import json
from pathlib import Path

OUTPUT_PATH = Path(__file__).parent
ASSETS_PATH = OUTPUT_PATH / Path("./assets")

def _relativeToAssets(path: str) -> Path:
    return ASSETS_PATH / Path(path)

# where we will save our configuration
DIR_PATH = os.path.join(os.environ["APPDATA"], "Eyes_Protection_Reminder")
FILE_CONFIG = os.path.join(DIR_PATH, str("config.json"))

# where are store the config
DATA = {}

def _loadDefaultSettings():
    with open(_relativeToAssets("default_setting.json"), "r") as in_file:
        global DATA
        DATA = json.load(in_file)

def _loadSettings():
    # check the directory
    if not os.path.exists(DIR_PATH):
        os.makedirs(DIR_PATH)
    
    # check the configuration file
    if not os.path.exists(FILE_CONFIG):
        _loadDefaultSettings()
    else:
        with open(FILE_CONFIG, "r") as in_file:
            global DATA
            DATA = json.load(in_file)

def _saveSettings():
    with open(FILE_CONFIG, "w") as out_file:
        global DATA
        json.dump(DATA, out_file)

def _getConfig(id: str) -> str:
    global DATA
    return DATA[id]

def _setConfig(id: str, value: str):
    global DATA
    DATA[id] = value
    _saveSettings()

RelativeToAssets = _relativeToAssets

LoadSettings    = _loadSettings
SaveSettings    = _saveSettings
GetConfig       = _getConfig
SetConfig       = _setConfig