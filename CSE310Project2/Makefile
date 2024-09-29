PJ2	:main.o util.o heap.o
	 g++ -Wall -o PJ2 main.o util.o heap.o

main.o	:main.cpp data_structures.h util.h heap.h
	 g++ -Wall -c main.cpp

util.o	:util.cpp data_structures.h util.h
	 g++ -Wall -c util.cpp

heap.o	:heap.cpp data_structures.h heap.h
	 g++ -Wall -c heap.cpp

clean	:
	rm *.o PJ2
