IDIR =../include
CC=g++
CFLAGS=-ftest-coverage -fprofile-arcs -I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lm -lgtest

_DEPS = string_soma.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = string_soma.o testa_string_soma.o testa_string_soma_stdin.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

string_soma: $(OBJ)
	g++ -o $@ $^ $(CFLAGS) $(LIBS)

cppcheck:
	cppcheck string_soma.cpp testa_string_soma.cpp testa_string_soma_stdin.cpp --enable=warning 

gcov:
	string_soma.cpp testa_string_soma.cpp testa_string_soma_stdin.cpp
help:
	#	
	#--write "make gcov" for using gcov in the .cpp files
	#
	#--write "make cppcheck" for using cppcheck in .cpp files
	#
	

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

