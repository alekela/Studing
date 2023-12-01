all: main.exe clean

main.exe: main.o Rational.o
	g++ main.o Rational.o -o main.exe -g

main.o: main.cpp
	g++ -c main.cpp -o main.o -g
	
Rational.o: Rational.cpp
	g++ -c Rational.cpp -o Rational.o -g
 
clean:
	rm -rf *.o