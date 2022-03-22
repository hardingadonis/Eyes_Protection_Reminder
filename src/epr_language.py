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

import epr_config as Config

EN = {
    "EPR_01": "Change reminder time",
    "EPR_02": "5 minutes",
    "EPR_03": "10 minutes",
    "EPR_04": "15 minutes",
    "EPR_05": "20 minutes",
    "EPR_06": "25 minutes",
    "EPR_07": "30 minutes",
    "EPR_08": "35 minutes",
    "EPR_09": "40 minutes",
    "EPR_10": "45 minutes",
    "EPR_11": "50 minutes",
    "EPR_12": "55 minutes",
    "EPR_13": "60 minutes",
    "EPR_14": "Not remind",
    "EPR_15": "Language (Restart to apply)",
    "EPR_16": "English",
    "EPR_17": "Tiếng Việt",
    "EPR_18": "Source code",
    "EPR_19": "Exit",
    "EPR_20": "Hey bro, the time is already. Relax now 🐧🐧🐧"
}

VI = {
    "EPR_01": "Thay đổi thời gian nhắc nhở",
    "EPR_02": "5 phút",
    "EPR_03": "10 phút",
    "EPR_04": "15 phút",
    "EPR_05": "20 phút",
    "EPR_06": "25 phút",
    "EPR_07": "30 phút",
    "EPR_08": "35 phút",
    "EPR_09": "40 phút",
    "EPR_10": "45 phút",
    "EPR_11": "50 phút",
    "EPR_12": "55 phút",
    "EPR_13": "60 phút",
    "EPR_14": "Không nhắc nhở",
    "EPR_15": "Ngôn ngữ (Khởi động lại để áp dụng)",
    "EPR_16": "English",
    "EPR_17": "Tiếng Việt",
    "EPR_18": "Source code",
    "EPR_19": "Thoát",
    "EPR_20": "Ey bạn, thời gian tới rồi đấy. Thư giãn đê 🐧🐧🐧"
}

def _getLanguage(id: str) -> str:
    language = Config.GetConfig("language")

    if language == "en":
        return EN[id]
    elif language == "vi":
        return VI[id]
    else:
        return EN[id]

GetLanguage = _getLanguage