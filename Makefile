#Talia Lee tl2db 3/12 Makefile
CXX=clang++ -std=c++11


a.out: wordPuzzle.o hashTable.o timer.o
	$(CXX) -Wall wordPuzzle.o hashTable.o timer.o

wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h
	$(CXX) -c wordPuzzle.cpp

hashTable.o: hashTable.cpp hashTable.h
	$(CXX) -c hashTable.cpp

timer.o: timer.cpp timer.h
	$(CXX) -c timer.cpp



hashTable.o: hashTable.cpp hashTable.h
timer.o: timer.cpp timer.h
wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h
