SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/pruebacronologia
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
$(BIN)/pruebacronologia: $(OBJ)/pruebacronologia.o $(OBJ)/FechaHistorica.o $(OBJ)/Cronologia.o
	$(CXX) -Wall -g -o $(BIN)/pruebacronologia $(OBJ)/FechaHistorica.o $(OBJ)/Cronologia.o $(OBJ)/pruebacronologia.o

$(OBJ)/pruebacronologia.o : $(SRC)/pruebacronologia.cpp $(INC)/Cronologia.h $(INC)/FechaHistorica.h
	$(CXX) $(CPPFLAGS) -I./$(INC) $(SRC)/pruebacronologia.cpp -o $(OBJ)/pruebacronologia.o

$(OBJ)/Cronologia.o : $(SRC)/Cronologia.cpp $(INC)/Cronologia.h $(INC)/FechaHistorica.h $(INC)/VectorDinamico.h $(INC)/VectorDinamico.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) $(SRC)/Cronologia.cpp -o $(OBJ)/Cronologia.o
	
$(OBJ)/FechaHistorica.o : $(SRC)/FechaHistorica.cpp $(INC)/FechaHistorica.h $(INC)/VectorDinamico.h $(INC)/VectorDinamico.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) $(SRC)/FechaHistorica.cpp -o $(OBJ)/FechaHistorica.o

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*

tgz: 
	tgz EDP2.tgz
