# Eyes Protection Reminder
> With 20:20:20 rule, this tool will get rid of your eyes problems. Enjoys!!!  

[![Build Status](https://github.com/hardingadonis/Eyes_Protection_Reminder/actions/workflows/build.yml/badge.svg)](https://github.com/hardingadonis/Eyes_Protection_Reminder/actions)
[![Release Status](https://github.com/hardingadonis/Eyes_Protection_Reminder/actions/workflows/release.yml/badge.svg)](https://github.com/hardingadonis/Eyes_Protection_Reminder/actions)
![Languages](https://img.shields.io/github/languages/top/hardingadonis/Eyes_Protection_Reminder?style=flat)
![Repo Size](https://img.shields.io/github/repo-size/hardingadonis/Eyes_Protection_Reminder?style=flat)
![License](https://img.shields.io/github/license/hardingadonis/Eyes_Protection_Reminder?style=flat)
[![Download](https://img.shields.io/github/downloads/hardingadonis/Eyes_Protection_Reminder/v4.1.2/total?style=flat)](https://github.com/hardingadonis/Eyes_Protection_Reminder/releases/tag/v4.1.2)

![EPR_banner](https://github.com/hardingadonis/Eyes_Protection_Reminder/blob/main/imgs/EPR_banner.png)

## Introduction

You are a student?

You are a software engineer?

Do you have to use a laptop, a desktop for a long time?

Don't worry, that tool is for you!!!

Let see...

## Showcase

<p align="center">
  <img src="https://github.com/hardingadonis/Eyes_Protection_Reminder/blob/main/imgs/EPR_showcase.png" />
</p>

## Requirements
- Windows OS (just only Windows, not Linux or macOS)
- C++ Compiler such as:
  - Microsoft Visual C++
  - Intel C++ Compiler
  - GNU Compiler Collection
  - Clang
  - ...
- CMake 3.10.2 or above

## Install

- Clone repository
```bash
git clone https://github.com/hardingadonis/Eyes_Protection_Reminder.git
cd Eyes_Protection_Reminder/
```

- Clone submodule repository
```bash
git submodule update --init --recursive
```

- Build project form sources
```bash
mkdir build
cd build
cmake ..
cmake --build . --target EPR
```

- Run project
  - Find an application that named `Eyes_Protection_Reminder_v4.1.2.Windows.x86.exe` or `Eyes_Protection_Reminder_v4.1.2.Windows.x64.exe`
  - Now, run it!!!

- Or, you can download the binary in [here](https://github.com/hardingadonis/Eyes_Protection_Reminder/releases/tag/v4.1.2)

## Usage

You do not know how to use this tool?

Don't worry, click here to know usage: [Usage](https://github.com/hardingadonis/Eyes_Protection_Reminder/blob/main/docs/Usage.md) or [Usage (for Vietnamese)](https://github.com/hardingadonis/Eyes_Protection_Reminder/blob/main/docs/Usage_vi_VN.md)

## License

MIT License

Copyright (c) 2022 [Minh Vương](https://github.com/hardingadonis)

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

## External libraries and assets used by Eyes Protection Reminder

- *[wxWidgets](https://github.com/wxWidgets/wxWidgets)* is under the [wxWindows Library Licence](https://opensource.org/licenses/wxwindows.php)

- *[EPR_icon](https://github.com/hardingadonis/Eyes_Protection_Reminder/blob/main/assets/EPR_icon.png)* is under the [flaticon](https://www.flaticon.com/free-icon/eyes_599324)