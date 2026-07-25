CXXFLAGS = -O2 -std=c++17

amrikac: main.o lex.o emit.o parse.o
	g++ main.o lex.o emit.o parse.o -o amrikac

main.o: bin/main.cpp
	g++ $(CXXFLAGS) bin/main.cpp -c

lex.o: bin/lex.cpp
	g++ $(CXXFLAGS) bin/lex.cpp -c

emit.o: bin/emit.cpp
	g++ $(CXXFLAGS) bin/emit.cpp -c

parse.o: bin/parse.cpp
	g++ $(CXXFLAGS) bin/parse.cpp -c
clean:
	rm -f *.o *.c *.out bin/*.gch amrikac
