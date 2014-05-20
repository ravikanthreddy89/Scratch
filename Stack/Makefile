#variables
CC=g++
CFLAGS= -c -Wall
source=./src
binary=./bin
inc=./include

#targets and dependencies
all: tests

tests : test1

test1 :  $(binary)/stack.o $(binary)/test1.o  
	$(CC) $(binary)/*.o -o $(binary)/test1

$(binary)/stack.o : $(source)/stack.cpp
	$(CC) $(CFLAGS) $(source)/stack.cpp -o $(binary)/stack.o

$(binary)/test1.o : ./tests/test1.cpp
	$(CC) $(CFLAGS) ./tests/test1.cpp -o $(binary)/test1.o


clean :
	rm -r $(binary)/*