#A1 makefile

CC=g++
lib=-std=c++11 

Database.o: Database.cpp
	$(CC) -c -o Database.o Database.cpp $(lib) 

#Database: Database.o
	$(CC) -o Database Database.o $(lib) 

run:
	./Database
clean:
	rm -f *.o Database

