all: test usecase analysis

test: test_hash_table.o hash_table.o element.o
	g++ -o test $^

usecase: main.o usecase.o hash_table.o element.o
	g++ -o usecase $^

analysis: analysis.o hash_table.o element.o
	g++ -o analysis $^

main.o: main.cpp usecase.cpp hash_table.h element.h
	g++ -c $<

test_hash_table.o: test_hash_table.cpp hash_table.h element.h
	g++ -c $<

analysis.o: analysis.cpp hash_table.h element.h
	g++ -c $<

hash_table.o: hash_table.cpp hash_table.h
	g++ -c $<

element.o: element.cpp element.h
	g++ -c $<

usecase.o: usecase.cpp
	g++ -c $<

clean:
	rm -f *.o test usecase analysis