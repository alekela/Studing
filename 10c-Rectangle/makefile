all: 10c.exe

10c.exe: 10c.o Rectangle.o
	g++ 10c.o Rectangle.o -o 10c.exe

10c.o: 10c.cpp
	g++ -c 10c.cpp -o 10c.o

Rectangle.o: Rectangle.cpp
	g++ -c Rectangle.cpp -o Rectangle.o

clean:
	rm -rf *.o 10c.exe