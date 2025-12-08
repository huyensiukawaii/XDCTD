CFLAGS = -c -Wall
CC = gcc
LIBS =  -lm 

all: symtab

symtab: main.o symtab.o debug.o
	${CC} main.o symtab.o debug.o -o symtab

main.o: main.c
	${CC} ${CFLAGS} main.c

symtab.o: symtab.c
	${CC} ${CFLAGS} symtab.c

debug.o: debug.c
	${CC} ${CFLAGS} debug.c

clean:
ifeq ($(OS),Windows_NT)
    RM = del /Q
    EXT = .exe
else
    RM = rm -f
    EXT =
endif

ifeq ($(OS),Windows_NT)
    RM = del /Q
    EXT = .exe
else
    RM = rm -f
    EXT =
endif

clean:
	$(RM) *.o 2>nul || true
