all: main.exe clean

main.exe: main.o queue.o stack.o
	g++ main.o queue.o stack.o -o main.exe -g

main.o: main.cpp
	g++ -c main.cpp -o main.o -g
	
queue.o: queue.cpp
	g++ -c queue.cpp -o queue.o -g

stack.o: stack.cpp
	g++ -c stack.cpp -o stack.o -g
 
clean:
	rm -rf *.o