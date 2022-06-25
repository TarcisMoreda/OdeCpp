CC=g++
FLAGS=-g -Wall -O2 -std=c++11

SRC=../src
INC=../include
OBJ_DYN=obj_dyn
OBJ_STT=obj_stt
SRCS=$(wildcard $(SRC)/*.cpp)
OBJS_DYN=$(patsubst $(SRC)/%.cpp, $(OBJ_DYN)/%.o, $(SRCS))
OBJS_STT=$(patsubst $(SRC)/%.cpp, $(OBJ_STT)/%.o, $(SRCS))
HDRS=$(wildcard $(INC)/*.hpp)
LIB_DYN=libOdeCpp.so
LIB_STT=libOdeCpp.a

DESTDIR=/usr
PREFIX=OdeCpp

all: dynamic static

install: dynamic
	@echo "Installing dynamic library..."
	@echo "Creating directory: $(DESTDIR)/include/$(PREFIX)/"
	@mkdir -p $(DESTDIR)/include/$(PREFIX)/
	@echo "Moving headers to $(DESTDIR)/include/$(PREFIX)/"
	@cp -r $(INC)/* $(DESTDIR)/include/$(PREFIX)/
	@echo "Moving dynamic library to $(DESTDIR)/lib/"
	@cp $(LIB_DYN) $(DESTDIR)/lib/

dynamic: $(LIB_DYN)

$(LIB_DYN): $(OBJS_DYN) $(OBJ_DYN)
	$(CC) $(OBJS_DYN) $(FLAGS) -fPIC -shared -o $(LIB_DYN)

$(OBJ_DYN)/%.o: $(SRC)/%.cpp $(OBJ_DYN)
	$(CC) $(FLAGS) -fPIC -c $< -o $@

$(OBJ_DYN):
	@mkdir -p $@

static: $(LIB_STT)

$(LIB_STT): $(OBJS_STT) $(OBJ_STT)
	@echo "Creating static library..."
	@echo "Linking static library..."
	@ar rcs $(LIB_STT) $(OBJS_STT)

$(OBJ_STT)/%.o: $(SRC)/%.cpp $(OBJ_STT)
	$(CC) $(FLAGS) -fPIC -c $< -o $@

$(OBJ_STT):
	@mkdir -p $@

clean:
	$(RM) -r $(OBJ_DYN) $(OBJ_STT)
	$(RM) $(LIB_DYN) $(LIB_STT)