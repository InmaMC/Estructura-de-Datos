SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g -I./$(INC) -c


all: $(BIN)/testStackMaxVD $(BIN)/testStackMaxQ
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
$(BIN)/testStackMaxQ: $(OBJ)/StackMaxQ.o $(OBJ)/testStackMaxQ.o
	$(CXX) -Wall -g -o $(BIN)/testStackMaxQ $(OBJ)/StackMaxQ.o $(OBJ)/testStackMaxQ.o

$(BIN)/testStackMaxVD: $(OBJ)/StackMaxVD.o $(OBJ)/testStackMaxVD.o
	$(CXX) -Wall -g -o $(BIN)/testStackMaxVD $(OBJ)/StackMaxVD.o $(OBJ)/testStackMaxVD.o

$(OBJ)/testStackMaxQ.o : $(SRC)/testStackMaxQ.cpp $(INC)/StackMaxQ.h
	$(CXX) $(CPPFLAGS) $(SRC)/testStackMaxQ.cpp -o $(OBJ)/testStackMaxQ.o

$(OBJ)/testStackMaxVD.o : $(SRC)/testStackMaxVD.cpp $(INC)/StackMaxVD.h
	$(CXX) $(CPPFLAGS) $(SRC)/testStackMaxVD.cpp -o $(OBJ)/testStackMaxVD.o

$(OBJ)/StackMaxQ.o : $(SRC)/StackMaxQ.cpp $(INC)/StackMaxQ.h $(INC)/Queue.h $(INC)/Queue.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/StackMaxQ.cpp -o $(OBJ)/StackMaxQ.o
	
$(OBJ)/StackMaxVD.o : $(SRC)/StackMaxVD.cpp $(INC)/StackMaxVD.h $(INC)/VD.h $(INC)/VD.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/StackMaxVD.cpp -o $(OBJ)/StackMaxVD.o

# ************ Limpieza ************
clean :
	-rm $(OBJ)/*

mrproper : clean
	-rm $(BIN)/* doc/html/*

tgz: 
	tgz StackMax.tgz
