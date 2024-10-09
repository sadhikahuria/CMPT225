all: final

final: StringList.o StringListTest.o
	g++ StringList.o StringListTest.o -o final

StringList.o: StringList.cpp StringList.h
	g++ -c StringList.cpp

StringListTest.o: StringListTest.cpp StringList.h
	g++ -c StringListTest.cpp

clear:
	rm -f *.o final
