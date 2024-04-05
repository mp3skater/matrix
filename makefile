# Makefile for a C program from ChatGBT

CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = matest
SRC = matrix.c test_matrix.c # Add all your source files here
OBJ = $(SRC:.c=.o)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJ)

