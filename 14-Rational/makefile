all: main.exe

main.exe: main.o Rational.o
	g++ main.o Rational.o -o main.exe

main.o: main.cpp
	g++ -c main.cpp -o main.o
	
Rational.o: Rational.cpp
	g++ -c Rational.cpp -o Rational.o

clean:
	rm -rf *.o main.exe