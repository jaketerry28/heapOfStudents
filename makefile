main: address.o date.o main.o
	g++ -g address.o date.o main.o -o main

main.o: address.h date.h main.cpp
	g++ -c -g main.cpp

date.o: date.h date.cpp
	g++ -c -g date.cpp

address.o: address.h address.cpp
	g++ -c -g address.cpp

clean:
	rm *.o

run: main
	./main

debug: main
	gdb main
