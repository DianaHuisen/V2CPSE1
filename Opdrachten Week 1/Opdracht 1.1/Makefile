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
SOURCES := print_asciz.asm


# header files in this project
HEADERS :=

# other places to look for files for this project
SEARCH  := 

# suppress some optimization which would detect the error at compile timre
PROJECT_C_FLAGS := -fno-aggressive-loop-optimizations

# set RELATIVE to the next higher directory 
# and defer to the Makefile.* there
RELATIVE := ..
include $(RELATIVE)/Makefile.due
