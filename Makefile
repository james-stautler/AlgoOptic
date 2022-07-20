
main: main.o bar.o collection.o
	g++ main.o bar.o collection.o -o main -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp 

bar.o: bar.cpp
	g++ -c bar.cpp bar.h

collection.o: collection.cpp
	g++ -c collection.cpp collection.h

clean:
	rm *.o main