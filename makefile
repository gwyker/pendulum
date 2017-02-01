
CC = g++
CFLAGS = -g 
COPTFLAGS = 
LIBFLAGS = -lglut -lGLU -lGL -lm
HEADERS = prototypes.h
OBJECTS = 

all : pristine pendulum clean

pendulum : main.o $(OBJECTS)
	$(CC) main.o $(OBJECTS) -o pendulum $(LIBFLAGS)

main.o : main.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c main.cpp

clean :
	rm *.o

pristine :
	rm -f *.o
	rm -f *~
	touch *.cpp

ctags :
	ctags *.cpp
