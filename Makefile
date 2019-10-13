CC=gcc
CFLAGS=-Wall -Werror
LDFLAGS=$(CFLAGS) -pthread
OBJ=light.o
TARGET=controller



$(TARGET): light.o
	$(CC) -o $@ $(LDFLAGS) $(TARGET).c $^
	
all:
	make $(TARGET)

clean:
	rm -rf $(OBJ) $(TARGET) *~
