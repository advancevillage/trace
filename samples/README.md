
说明
---
[下载opencv的开源代码 https://github.com/opencv/opencv](https://github.com/opencv/opencv)

###实例的目录组织结构
	workpath
	|-------xxx.cpp (源文件)
	|
	|-------Makefile 


###采用统一的编译框架，日后直接将裤架文件拷贝到工作目录，make命令生成目标文件
	#用户定义输出可执行文件或者库的文件名
	NAME=testreadimage
	#路径信息设置:在当前目录make命令会产生2个目录(bin和obj),bin存储可执行文件，obj
	#存储目标文件
	#WORKPATH=$(shell pwd)
	#BINDIR=$(WORKPATH)/bin
	#OBJDIR=$(WORKPATH)/obj
	BINDIR=bin
	OBJDIR=obj
	#设置编译信息
	CXX=g++
	RM=rm -rf
	CXXFLAGS= -O3
	BASEDIR=/opt/release
	INCLUDES= -I$(BASEDIR)/include
	LIBS= -L$(BASEDIR)/lib \
	      -lopencv_core  -lopencv_face -lopencv_highgui \
	      -lopencv_imgcodecs  -lopencv_ml  -lopencv_shape  \
	      -lopencv_text  -lopencv_videoio  -lopencv_video  \
	
	SRCS=$(wildcard *.cpp)
	TEMP=$(patsubst %.cpp,%.o,$(SRCS))
	OBJS=$(foreach value,$(TEMP),$(OBJDIR)/$(value))
	TARGET=$(BINDIR)/$(NAME)
	
	#开始命令执行
	all:$(OBJDIR) $(BINDIR) $(TARGET)
	$(OBJDIR):
	    mkdir -p $@
	$(BINDIR):
	    mkdir -p $@
	$(TARGET): $(OBJS)
	    $(CXX) $(CXXFLAGS) $^ $(LIBS) -o $@ -g
	$(OBJS): $(SRCS)  
	    $(CXX) $(CXXFLAGS) -c $< $(INCLUDES) -o $@ -g
	clean:
	    $(RM)  $(OBJDIR)
	    $(RM)  $(BINDIR)
---
###LCIENCE
CUG@2016 SUN-HE