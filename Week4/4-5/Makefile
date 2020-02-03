#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := compressed.asm decompress.asm

# header files in this project
HEADERS := 

# other places to look for files for this project
SEARCH  := 


compressed.asm: compressed.asm compressor
	./compressor

compressor: compressor.cpp match.hpp compressor.hpp wilhelmus.txt
	g++ -std=c++17 compressor.cpp -o compressor

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
#include $(RELATIVE)Makefile.native
include $(RELATIVE)Makefile.due
