CC=g++
FLAGS=-g -Wall -O2 -std=c++11

SRC=../src
OBJ_DYN=obj_dyn
OBJ_STT=obj_stt
SRCS=$(wildcard $(SRC)/*.cpp)
OBJS_DYN=$(patsubst $(SRC)/%.cpp, $(OBJ_DYN)/%.o, $(SRCS))
OBJS_STT=$(patsubst $(SRC)/%.cpp, $(OBJ_STT)/%.o, $(SRCS))
HDRS=$(wildcard $(SRC)/*.hpp)
HDRS+=$(wildcard $(SRC)/*/*.hpp)
LIB_DYN=libOdeCpp.so
LIB_STT=libOdeCpp.a

DESTDIR=/usr
PREFIX=OdeCpp

all: install

install: dynamic
	@echo "Installing dynamic library..."
	@echo "Creating directory: $(DESTDIR)/include/$(PREFIX)/"
	@mkdir -p $(DESTDIR)/include/$(PREFIX)/
	@echo "Moving headers to $(DESTDIR)/include/$(PREFIX)/"
	@cp -r $(HDRS) $(DESTDIR)/include/$(PREFIX)/
	@echo "Moving dynamic library to $(DESTDIR)/lib/"
	@cp $(LIB_DYN) $(DESTDIR)/lib/
	@echo "Installation complete."

dynamic: clean $(LIB_DYN)

$(LIB_DYN): $(OBJS_DYN) $(OBJ_DYN)
	@$(CC) $(OBJS_DYN) $(FLAGS) -fPIC -shared -o $(LIB_DYN)

$(OBJ_DYN)/%.o: $(SRC)/%.cpp $(OBJ_DYN)
	@$(CC) $(FLAGS) -fPIC -c $< -o $@

$(OBJ_DYN):
	@mkdir -p $@

static: clean $(LIB_STT)

$(LIB_STT): $(OBJS_STT) $(OBJ_STT)
	@echo "Creating static library..."
	@echo "Linking static library..."
	@ar rcs $(LIB_STT) $(OBJS_STT)
	@echo "Static library created."

$(OBJ_STT)/%.o: $(SRC)/%.cpp $(OBJ_STT)
	@$(CC) $(FLAGS) -fPIC -c $< -o $@

$(OBJ_STT):
	@mkdir -p $@

uninstall:
	@echo "Uninstalling dynamic library..."
	@rm -rf $(DESTDIR)/include/$(PREFIX)
	@rm -rf $(DESTDIR)/lib/$(LIB_DYN)

clean:
	@echo "Cleaning files..."
	@rm -rf $(OBJ_DYN) $(OBJ_STT)
	@rm -f $(LIB_DYN) $(LIB_STT)
	@rm -rf ../docs/doxygen
	@echo "Files cleaned."

docs:
	@echo "Generating docs..."
	@doxygen ./Doxyfile
	@firefox ../docs/doxygen/html/index.html