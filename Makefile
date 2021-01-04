all: cgol dynCGOL

cgol: cgol.c
	gcc -ansi -Wall -o cgol cgol.c

dynCGOL: dynCGOL.c
	gcc -ansi -Wall -o dynCGOL dynCGOL.c

clean:
	rm *.o cgol dynCGOL
