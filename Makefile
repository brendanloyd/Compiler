CC = g++
CFLAGS = -g -Wall -std=c++11
OBJS = main.o scanner.o parser.o testTree.o traversals.o
TARGET = P2

genCode: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o genCode

main.o: main.cpp main.h token.h scanner.h parser.h node.h testTree.h
	$(CC) $(CFLAGS) -c main.cpp

scanner.o: scanner.cpp scanner.h
	$(CC) $(CFLAGS) -c scanner.cpp

parser.o: parser.cpp parser.h
	$(CC) $(CFLAGS) -c parser.cpp
 
testTree.o: testTree.cpp testTree.h
	$(CC) $(CFLAGS) -c testTree.cpp
 
traversals.o: traversals.cpp traversals.h
	$(CC) $(CFLAGS) -c traversals.cpp