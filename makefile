main: address.o main.o
	g++ -g address.o main.o -o main

main.o: address.h main.cpp
	g++ -c -g main.cpp

address.o: address.h address.cpp
	g++ -c -g address.cpp

clean:
	rm *.o

run: main
	./main

debug: main
	gdb main
