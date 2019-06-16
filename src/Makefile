# IDIR is the directory for header files
IDIR =../include

# This is the compiler
CC=g++

# flags, i.e. option to pass to the compiler (tell where to search for stuff)
CFLAGS=-I$(IDIR)

# directory of .o files
ODIR=obj

# directory of libraries
LDIR =../lib

# libraries to add to the compiler
LIBS=-lm

# possible local header file
_DEPS =pok.h

# Put local header file in _DEPS and the one in include folder from IDIR, $ symbol is to call the variables
# you defined; % is for all the files under the IDIR directory;
# $(patsubst pattern,replacement,text) Finds whitespace-separated words in text that match pattern and
# replaces them with replacement; here every time you find something in _DEPS (here pok.h), you
# substitute with IDIR/something (so the output in this case will be DEPS = ../include/pok.h
DEPS =$(patsubst %,$(IDIR)/%,$(_DEPS))

# takes all the sources in this directory
SOURCES =$(wildcard *.cxx)

_OBJ =$(patsubst %.cxx,%.o,$(SOURCES))
# Retrieving the object files specified in _OBJ in the subdirectory ODIR (here obj)
OBJ =$(patsubst %,$(ODIR)/%,$(_OBJ))

# targets are the object files in directory specified by ODIR, % is a special character (like * in bash);
# the prerequisites are the .c (.cpp,.cxx) files that have same name as the .o file (represented by %) and the
# header file in DEPS, that is compile looking at changes in the prerequisites
# $@ looks at the left of : whereas $< is the first prerequisite (here %.c, the source file)
$(ODIR)/%.o: %.cxx $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# $^ takes all prerequisites (the thing at the right of :)
pokemon: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean
# clean the directory from all .o objects
clean:
	rm -f $(ODIR)/*.o
