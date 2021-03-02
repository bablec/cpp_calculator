CFLAGS = -c -I$(HOME)/Libraries/include
LFLAGS = -L$(HOME)/Libraries/lib
LIB = -ldataStructures

project: main.o
	g++ $(LFLAGS) -o project main.o $(LIB)

main.o: main.cc
	g++ $(CFLAGS) main.cc