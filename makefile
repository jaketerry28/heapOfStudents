main: address.o date.o student.o main.o 
	g++ -g address.o date.o student.o main.o -o main

main.o: address.h date.h student.h main.cpp
	g++ -c -g main.cpp

student.o: student.h student.cpp
	g++ -c -g student.cpp

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