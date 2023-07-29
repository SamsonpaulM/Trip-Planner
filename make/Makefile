GCC = g++
BIN = ../bin
OBJ = ../obj
SRC = ../src
INC = ../header
LFLAGS = -o
IFLAGS = -I $(INC)
CFLAGS = -c -g -Wall


trip: tripPlanner.o dataLoad.o booking.o adminMenu.o admin.o clientMenu.o client.o 
	$(GCC) $(LFLAGS) $(BIN)/tripPlanner.exe $(OBJ)/tripPlanner.o $(OBJ)/dataLoad.o $(OBJ)/booking.o $(OBJ)/adminMenu.o  $(OBJ)/admin.o $(OBJ)/clientMenu.o $(OBJ)/client.o 

tripPlanner.o: $(SRC)/tripPlanner.cpp
	$(GCC) $(LFLAGS) $(OBJ)/tripPlanner.o $(SRC)/tripPlanner.cpp $(CFLAGS) $(IFLAGS)

dataLoad.o: $(SRC)/dataLoad.cpp
	$(GCC) $(LFLAGS) $(OBJ)/dataLoad.o $(SRC)/dataLoad.cpp $(CFLAGS) $(IFLAGS)

booking.o: $(SRC)/booking.cpp
	$(GCC) $(LFLAGS) $(OBJ)/booking.o $(SRC)/booking.cpp $(CFLAGS) $(IFLAGS)

adminMenu.o: $(SRC)/adminMenu.cpp
	$(GCC) $(LFLAGS) $(OBJ)/adminMenu.o $(SRC)/adminMenu.cpp $(CFLAGS) $(IFLAGS)

admin.o: $(SRC)/admin.cpp
	$(GCC) $(LFLAGS) $(OBJ)/admin.o $(SRC)/admin.cpp $(CFLAGS) $(IFLAGS)

clientMenu.o: $(SRC)/clientMenu.cpp
	$(GCC) $(LFLAGS) $(OBJ)/clientMenu.o $(SRC)/clientMenu.cpp $(CFLAGS) $(IFLAGS)

client.o: $(SRC)/client.cpp
	$(GCC) $(LFLAGS) $(OBJ)/client.o $(SRC)/client.cpp $(CFLAGS) $(IFLAGS)

clean:
	rm $(OBJ)/*.o $(BIN)/*.exe