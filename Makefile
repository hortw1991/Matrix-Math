compile:
	g++ -std=c++11 -Wall -pedantic-errors -c -o Matrix.o Matrix.cpp
	g++ -std=c++11 -Wall -pedantic-errors -c -o p1.o p1.cpp

link:
	g++ -std=c++11 -Wall -pedantic-errors -o p1 Matrix.o p1.o

run:
	./p1



