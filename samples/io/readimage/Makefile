#user set filename
NAME=testreadimage

#path information
#WORKPATH=$(shell pwd)
#BINDIR=$(WORKPATH)/bin
#OBJDIR=$(WORKPATH)/obj
BINDIR=bin
OBJDIR=obj

#comple options
CXX=g++
RM=rm -rf
CXXFLAGS= -O3
BASEDIR=/opt/release
INCLUDES= -I$(BASEDIR)/include
LIBS= -L$(BASEDIR)/lib \
	  -lopencv_core  -lopencv_face -lopencv_highgui \
	  -lopencv_imgcodecs  -lopencv_ml  -lopencv_shape  \
	  -lopencv_text  -lopencv_videoio  -lopencv_video  \
	  -lopencv_imgproc
	
#
SRCS=$(wildcard *.cpp)
TEMP=$(patsubst %.cpp,%.o,$(SRCS))
OBJS=$(foreach value,$(TEMP),$(OBJDIR)/$(value))
TARGET=$(BINDIR)/$(NAME)

#handle
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

