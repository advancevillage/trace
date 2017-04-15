<h2>概述</h2>
Trace， 本项目的效果是单摄像头动态物体跟踪。摄像头采用USB的方式插入笔记本。

<h2>目录</h2>

* [环境基础](#1)
* [目录配置](#2)
* [核心结构](#3)
* [操作流程](#4)
* [实验结果](#5)
* [版权](#6)

<h2 id="1">环境基础</h2>
操作系统： 16.04.1 Ubuntu x86_64 (kernel 4.8.0-41-generic)

窗口显示： [GTK+3.0](https://www.gtk.org/)  [GNOME(3.18)](https://www.gnome.org/)

开发环境： [codeblocks](https://launchpad.net/~damien-moore/+archive/ubuntu/codeblocks-stable), pkg-config

第三方库：[OpenCV](http://opencv.org/)

<h2 id="2">目录配置</h2>

```

  trace
    |----------main.cpp
    |
    |----------core
                 |----------object.h
                 |----------object.cpp
                 |----------objectnode.h
                 |----------objectnode.cpp
                 |----------objectarray.h
                 |----------objectarray.cpp
                 |----------objectcontroller.h
                 |----------objectcontroller.cpp
    |---------modules
                 |----------preprocessor
                            |----------preprocessor.h
                            |----------preprocessor.cpp
                 |----------foregrounddetection
                            |----------fgd.h
                            |----------fgd.cpp
                 |----------objectdetection
                            |----------od.h
                            |----------od.cpp
                 |----------objecttracker
                            |----------ot.h
                            |----------ot.cpp
                 |----------videocontroller
                            |----------videocontroller.h
                            |----------videocontroller.cpp
                            
```

<h2 id="3">核心结构</h2>

![object&objectnode](http://obp7hxe1q.bkt.clouddn.com/trace/core/core01.png)

![objectarray&objectcontroller](http://obp7hxe1q.bkt.clouddn.com/trace/core/core02.png)

<h2 id="4">操作流程</h2>

![主流程](http://obp7hxe1q.bkt.clouddn.com/trace/modules/modules01.png)

![详细模块](http://obp7hxe1q.bkt.clouddn.com/trace/modules/modules04.png)

![详细模块](http://obp7hxe1q.bkt.clouddn.com/trace/modules/modules03.png)

<h2 id="5">实验结果</h2>


<h2  id="6">LCIENCE</h2>
CUG@2016 SUN-HE