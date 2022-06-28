CXX=g++
FLAGS=-g -Wall -O2 -std=c++11 -fprofile-arcs -ftest-coverage
LIBS=-lgtest_main -lgtest -lpthread

SRC=../src
INC=../include
OBJ=obj
SRCS=$(wildcard $(SRC)/*.cpp)
OBJS=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))
HDRS=$(wildcard $(INC)/*.hpp)
DIR=report
INFO=$(DIR)/html/coverage.info
BIN=tests.bin

report: tests
	@echo "Generating gcov"
	@gcov -l tests.cpp
	@mkdir -p $(DIR)/gcov
	@mv *.gcda *.gcno $(DIR)/gcov
	@mv obj/*.gcda obj/*.gcno $(DIR)/gcov
	@mv *.gcov $(DIR)/gcov
	@echo "Generating html"
	@mkdir -p $(DIR)/html
	@lcov --capture --directory . --output-file $(INFO)
	@lcov --remove $(INFO) '/usr/include/*' '9/*' --directory . --output-file $(INFO)
	@genhtml $(INFO) --output-directory $(DIR)/html

tests: $(BIN)
	@echo "Running tests..."
	@./$(DIR)/$(BIN)

$(BIN): $(OBJS) $(OBJ)
	@mkdir -p $(DIR)
	$(CXX) $(FLAGS) ./tests.cpp $(OBJS) -o $(DIR)/$(BIN) $(LIBS)

$(OBJ)/%.o: $(SRC)/%.cpp $(OBJ)
	$(CXX) $(FLAGS) -c $< -o $@ $(LIBS)

$(OBJ):
	@mkdir -p $@

clean:
	$(RM) -r $(OBJ)
	$(RM) -r $(DIR)
	$(RM) tests.gcda tests.gcno