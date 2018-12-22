CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-std=c++14
LDFLAGS=
LDLIBS=

SRCDIR = src
OBJDIR = obj

SRCS := $(wildcard $(SRCDIR)/*.cpp)

# SRCS=MessageBus.cpp Message.cpp main.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: bus

bus: $(OBJS)
	$(CXX) $(LDFLAGS) -o bus $(OBJS) $(LDLIBS)

#main.o: main.cpp
#
#Message.o: Message.cpp
#
#MessageBus.o: MessageBus.cpp
#
clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) bus
