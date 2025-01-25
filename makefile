# Makefile for Tic-Tac-Toe game

CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99
TARGET = tic_tac_toe
SRC = main.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
