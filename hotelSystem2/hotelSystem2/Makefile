CC=g++
LIB=-lm
OBJ=main.o hotel_manage.o hotel.o room.o guest.o tools.o
BIN=hms.bin


all:$(OBJ)
	$(CC) $(OBJ) $(LIB) -o $(BIN)

%.o:%.cpp
	$(CC) -c $< -o $@

clean:
	rm $(OBJ) $(BIN)


