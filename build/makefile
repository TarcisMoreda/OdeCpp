CC=g++
FLAGS=-g -Wall -O2 -fPIC

SRC=../src
INC=../include
OBJ=obj
SRCS=$(wildcard $(SRC)/*.cpp)
OBJS=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))
HDRS=$(wildcard $(INC)/*.hpp)
LIB=OdeCpp.so

all: $(LIB)

$(LIB): $(OBJS) $(OBJ)
	$(CC) $(FLAGS) $(OBJS) -shared -o $(LIB)

$(OBJ)/%.o: $(SRC)/%.cpp $(OBJ)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ):
	mkdir -p $@

clean:
	$(RM) -r $(OBJ)
	$(RM) $(LIB)