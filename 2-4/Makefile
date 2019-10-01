#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source & header files in this project (main.cpp is automatically assumed)

HEADERS += rtttl_player.hpp
HEADERS += note.hpp

SOURCES += rtttl_player.cpp

# other places to look for files for this project
SEARCH  := 

build: native.exe

native.exe: main.cpp rtttl_player.cpp
	g++ -std=c++17 rtttl_player.cpp main.cpp -o native.exe

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.native