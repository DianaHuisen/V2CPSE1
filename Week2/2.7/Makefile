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

HEADERS += note.hpp
HEADERS += melody.hpp
SOURCES += meldody.cpp
HEADERS += note_player.hpp
#HEADERS += fur_elise.hpp

#HEADERS += my_player.hpp
#SOURCES += my_player.cpp


HEADERS += note_player_gpio.hpp
SOURCES += note_player_gpio.cpp

#HEADERS += rtttl_player.hpp
#SOURCES += rtttl_player.cpp

# other places to look for files for this project
SEARCH  := 

run: melody.cpp

melody.cpp: meldody.cpp generator
	./generator

generator: generator.o rtttl_player.o my_player.o
	g++ -std=c++17 generator.o rtttl_player.o my_player.o -o generator

generator.o: generator.cpp my_player.hpp rtttl_player.hpp
	g++ -std=c++17 -c generator.cpp -o generator.o

rtttl_player.o: rtttl_player.cpp rtttl_player.hpp note_player.hpp
	g++ -std=c++17 -c rtttl_player.cpp -o rtttl_player.o

my_player.o: my_player.cpp my_player.hpp note_player.hpp 
	g++ -std=c++17 -c my_player.cpp -o my_player.o
    


# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)/Makefile.due
#include $(RELATIVE)/Makefile.native
