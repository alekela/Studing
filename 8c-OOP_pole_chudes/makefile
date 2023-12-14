all: main.exe clean

main.exe: main.o 8c.o
	g++ main.o 8c.o -o main.exe -g

8c.o: 8c.cpp
	g++ -c 8c.cpp -o 8c.o -g

main.o: main.cpp
	g++ -c main.cpp -o main.o -g

clean:
	rm -rf *.o