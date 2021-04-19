all: sim

sim: main.o simulator.o heap.o printer.o request.o
	g++ main.o simulator.o heap.o printer.o request.o -o simulator

main.o: main.cpp
	g++ -c main.cpp

simulator.o: simulator.cpp
	g++ -c simulator.cpp

heap.o: heap.cpp
	g++ -c heap.cpp

printer.o: printer.cpp
	g++ -c printer.cpp

request.o: request.cpp
	g++ -c request.cpp

clean: 
	rm -rf *o simulator