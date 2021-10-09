.PHONY: all clean

OBJ=obj
BIN=bin
EXE=a.out

PARAMS=-std=c++11 -pthread

all: $(OBJ)/main.o $(OBJ)/class_Database.o $(OBJ)/class_ReaderWriterMutex.o $(OBJ)/class_ThreadGuard.o $(OBJ)/threadFunction.o
	g++ $(PARAMS) $(OBJ)/* -o $(BIN)/$(EXE)

$(OBJ)/main.o: main.cpp class_Database.h class_ThreadGuard.h threadFunction.h
	g++ -c $(PARAMS) main.cpp -o $(OBJ)/main.o

$(OBJ)/class_Database.o: class_Database.cpp class_ReaderWriterMutex.h
	g++ -c $(PARAMS) class_Database.cpp -o $(OBJ)/class_Database.o

$(OBJ)/class_ReaderWriterMutex.o: class_ReaderWriterMutex.cpp
	g++ -c $(PARAMS) class_ReaderWriterMutex.cpp -o $(OBJ)/class_ReaderWriterMutex.o

$(OBJ)/class_ThreadGuard.o: class_ThreadGuard.cpp
	g++ -c $(PARAMS) class_ThreadGuard.cpp -o $(OBJ)/class_ThreadGuard.o

$(OBJ)/threadFunction.o: threadFunction.cpp
	g++ -c $(PARAMS) threadFunction.cpp -o $(OBJ)/threadFunction.o
