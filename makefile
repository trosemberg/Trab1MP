# Consts:
# IncludeDIR = *.hpp DIR
# CC = gcc or g++
# DB = gdb
# CFLAGS = comp line flags (-ansi = ansi law; -Wall, -Wextra = warnings; -I./ = *.h DIR)
# ObjDIR = *.o DIR
# LibDIR = lib DIR
# LibDIR -> enable when using, put $(LIBS) at end of gogo's command
LibDIREC =./lib/
LibDIR =./lib/
IncludeDIR =./include/
CppDIR=./src/
ObjDIR=./src/obj/
GcovDIR=./src/gcov/
CC=g++ 
DB=gdb
CFLAGS=-ansi -Wall -Wextra -I$(IncludeDIR)
CFLAGSTEST=-ansi -Wall -Wextra -I$(IncludeDIR) -pthread -ftest-coverage -fprofile-arcs -lgtest
# LIBS=-lgtest

# Vars:
# -- ADAPT THIS IN YOUR PROGRAM --
headers = string_soma.hpp
mainObject = testa_soma_string_stdin
objects = string_soma.o

# Set of *.hpp on which the *.cpp depend
_DEPS = $(headers)
DEPS = $(patsubst %,$(IncludeDIR)%,$(_DEPS))

# Set of *.o
_OBJ = $(mainObject).o $(objects)
OBJ = $(patsubst %,$(ObjDIR)%,$(_OBJ))

# Gathers *.o
$(ObjDIR)%.o: $(CppDIR)%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

# Creates executable (Linux)
$(mainObject): $(OBJ)
	$(CC) -g -o $@ $^ $(CFLAGS) $(LIBS)
	touch entrada.txt
	touch saida.txt
# Gets the files and organize in the lib include src/obj structure
.PHONY: prepareDIR
prepareDIR:
	mkdir -p $(LibDIREC)
	mkdir -p $(IncludeDIR)
	mkdir -p $(CppDIR)
	mkdir -p $(ObjDIR)
	mkdir -p $(GcovDIR)
	mv *.hpp $(IncludeDIR); true
	mv *.cpp $(CppDIR); true

# Call for execution
.PHONY: execute
execute:
	./$(mainObject)

# Call for debugging
.PHONY: debug
debug:
	$(DB) ./$(mainObject)

# Call for cppcheck
.PHONY: cppcheck
cppcheck:
	cppcheck ./src/string_soma.cpp ./src/testa_soma_string_stdin.cpp --enable=warning

# Call for gteste
.PHONY: gteste
gteste:
	$(CC) -c -o $(ObjDIR)testa_string_soma.o $(CppDIR)testa_string_soma.cpp $(CFLAGSTEST)
	$(CC) -g -o testa_string_soma $(ObjDIR)testa_string_soma.o $(CFLAGSTEST)
	mv  -v $(ObjDIR)*.gcno $(GcovDIR)
	
# Call for rungteste
.PHONY: rungteste
rungteste:
	./testa_string_soma
	mv  -v $(ObjDIR)*.gcda $(GcovDIR)

# Call for valgrind
.PHONY: valgrind
valgrind:
	valgrind ./testa_string_soma
	mv  -v $(ObjDIR)*.gcda $(GcovDIR)


# Call for gcov
.PHONY: gcov
gcov:
	mv  -v $(GcovDIR)*.gcda $(CppDIR)
	mv  -v $(GcovDIR)*.gcno $(CppDIR)
	gcov $(CppDIR)testa_string_soma.cpp
	mv  -v $(CppDIR)*.gcno $(GcovDIR)
	mv  -v $(CppDIR)*.gcda $(GcovDIR)
	mv  -v ./*.gcov $(GcovDIR)

# Call for run
.PHONY: run
run:
	./testa_soma_string_stdin <entrada.txt >saida.txt

# Call for *.o clean up
.PHONY: clean
clean:
	rm -f $(ObjDIR)*.o
	rm -f $(GcovDIR)*.gcno
	rm -f $(GcovDIR)*.gcda
	rm -f $(GcovDIR)*.gcov
	rm -f ./testa_string_soma
	rm -f ./testa_soma_string_stdin
	rm -f ./entrada.txt
	rm -f ./saida.txt
	

# Call for help with this makefile's commands
.PHONY: help
help:
	@echo "\n\t Makefile\n"
	@echo " make............= compiles testa_soma_string_stdin "
	@echo " make prepareDIR.= prepares project in the "lib include src/obj" structure (use this if all files are with this makefile)"
	@echo " make execute....= executes succesfully compiled program"
	@echo " make debug......= (gdb) debugs succesfully compiled program"
	@echo " make cppcheck...= invokes cppcheck on all .cpp files in the directory, checking for all types of messages"
	@echo "                         *(except missingIncludeSystem - cppceck can't find the gtest library)"
	@echo " make clean......= removes objects from obj directory\n"
	@echo " make gteste.....= compiles testa_string_soma que é a bateria de teste do gtest"
	@echo " make rungteste..= roda o testa_string_soma"
	@echo " make valgrind...= roda o valgrind no gteste, pois ele tem varios testes em que se aloca dinamicamente" 
	@echo " make run........= roda testa_string_soma no formato mandado nas diretivas do prog" 
	@echo "\n\t End of Makefile Help\n"


