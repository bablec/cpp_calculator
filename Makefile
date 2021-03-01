project2: main.o fraction.o dictionary.o
	g++ -o project2 main.o fraction.o dictionary.o

main.o: main.cc stack.h fraction.h dictionary.h
	g++ -c main.cc

fraction.o: fraction.cc fraction.h
	g++ -c fraction.cc

dictionary.o: dictionary.cc dictionary.h fraction.h
	g++ -c dictionary.cc