all: test hash1 hash2 hash3 sampleRead

test: test_hash_table.o
	g++ -std=c++11 -Wall -g -o test test_hash_table.o

test_hash_table.o: test_hash_table.cpp hash_table.cpp hash_table.h
	g++ -std=c++11 -c -g -Wall test_hash_table.cpp

sampleRead: sampleRead.cpp Board.h Board.cpp
	g++ -o sampleRead sampleRead.cpp Board.cpp

hash3: main.cpp Board.h Board.cpp hash_table.cpp hash_table.h element.cpp element.h
	g++ -o hash3 -DHASHFUNCTION3 main.cpp Board.cpp hash_table.cpp element.cpp

hash2: main.cpp Board.h Board.cpp hash_table.cpp hash_table.h element.cpp element.h
	g++ -o hash2 -DHASHFUNCTION2 main.cpp Board.cpp hash_table.cpp element.cpp

hash1: main.cpp Board.h Board.cpp hash_table.h hash_table.cpp element.h element.cpp
	g++ -o hash1 -DHASHFUNCTION1 main.cpp Board.cpp hash_table.cpp element.cpp

clean:
	rm -f *.o test hash1 hash2 hash3 sampleRead
