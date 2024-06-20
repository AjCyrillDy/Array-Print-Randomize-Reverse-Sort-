CC = gcc
CFLAGS = -ansi -pedantic -Wall
FILES = arraymanip.c reverseArray.c randomizeArray.c sortArray.c printArray.c
OUT_EXE = ass2 

build:	$(OUT_EXE)

$(OUT_EXE): $(FILES)
	   $(CC) $(CFLAGS) -o $(OUT_EXE) $(FILES)

clean: 
	rm -f *.o core *.exe *~

rebuild: clean build