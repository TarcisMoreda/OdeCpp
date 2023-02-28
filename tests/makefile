CXX=g++
FLAGS=-g -Wall -O2 -fprofile-arcs -ftest-coverage
LIBS=-lgtest_main -lgtest -lpthread

SRC=../src
SRCS=$(wildcard $(SRC)/*.cpp)
SRCS+=./tests.cpp
HDRS=$(wildcard $(SRC)/*.hpp)
BIN=tests.bin

tests:
	@echo "Building tests..."
	@$(CXX) $(SRCS) $(FLAGS) -o $(BIN) $(LIBS)
	@mkdir -p coverage
	@mv ./*.*.gcno ./coverage
	@echo "Build completed."

run: tests
	@echo "Running tests..."
	@./tests.bin
	@mv ./*.*.gcda ./coverage
	@echo "Tests completed."

coverage: run
	@echo "Creating coverage report..."
	@lcov --capture --directory ./coverage --base-directory . -o coverage.out &&\
	lcov --remove coverage.out "*usr/include*" -o coverage.out &&\
	genhtml -o report coverage.out
	@mv coverage.out ./coverage

clean:
	@echo "Cleaning files..."
	@rm -r $(BIN)
	@rm -r ./coverage
	@rm -r ./report