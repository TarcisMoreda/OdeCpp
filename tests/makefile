CC=g++
FLAGS=-g -Wall -fprofile-arcs -ftest-coverage
LIBS=-lgtest_main -lgtest -lpthread

SRC=../src
SRCS=$(wildcard $(SRC)/*.cpp)
SRCS+=./tests.cpp
BIN=tests.bin

tests: clean
	@echo "Building tests..."
	@$(CC) $(SRCS) $(FLAGS) -o $(BIN) $(LIBS)
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
	@firefox ./report/index.html

clean:
	@echo "Cleaning files..."
	@rm -rf $(BIN)
	@rm -rf ./coverage
	@rm -rf ./report
	@rm -rf *.gcda