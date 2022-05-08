# Eyes Protection Reminder ![](https://github.com/hardingadonis/Eyes_Protection_Reminder/actions/workflows/build.yml/badge.svg) ![](https://github.com/hardingadonis/Eyes_Protection_Reminder/actions/workflows/release.yml/badge.svg)

With 20:20:20 rule, this tool will get rid of your eyes problems. Enjoys!!!

## I. Introduction

You are a student?

You are a software engineer?

Do you have to use a laptop, a desktop for a long time?

Don't worry, that tool is for you!!!

Let see...

## II. Requirements
- Windows OS (just only Windows, not Linux)
- Visual Studio (any version)
- CMake 3.10.2 or above

## III. Install

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
cmake .. -DCMAKE_BUILD_TYPE=MinSizeRel -DwxBUILD_SHARED=OFF -G"Visual Studio 17 2022" -Ax64
cmake --build . --config MinSizeRel
```

- Run project
```
Find an application that named EPR.exe
Now, run it!!!
```

- Or, you can download the binary in [here](https://github.com/hardingadonis/Eyes_Protection_Reminder/releases/tag/v4.x.x)

## IV. License

MIT License

Copyright (c) 2022 [Harding Adonis](https://github.com/hardingadonis), [hoanghy0112](https://github.com/hoanghy0112), [AlexPhoenix45](https://github.com/AlexPhoenix45)

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