CC = gcc
CFLAGS = -g -Wall
SRC = indexer.c
TARGET_EXEC = indexer.exe

all: $(TARGET_EXEC)

$(TARGET_EXEC): $(SRC)
	$(CC) $(CFLAGS) $< -o $@

clean:
	-del /f /q indexer.exe

.PHONY: all clean