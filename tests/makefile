CC=g++
FLAGS=-g -Wall -O2

SRC=../src
INC=../include
OBJ=obj
SRCS=$(wildcard $(SRC)/*.cpp)
OBJS=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))
HDRS=$(wildcard $(INC)/*.hpp)
BIN=tests.bin

all: $(BIN)

$(BIN): $(OBJS) $(OBJ)
	$(CC) $(FLAGS) ./tests.cpp $(OBJS) -o $(BIN)

$(OBJ)/%.o: $(SRC)/%.cpp $(OBJ)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ):
	mkdir -p $@

clean:
	$(RM) -r $(OBJ)
	$(RM) $(BIN)