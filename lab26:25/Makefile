all: exe lib

exe:	deck.h main.c lib
	gcc main.c -L. -lDeck -o prog

lib:	deck.h deck.c
	gcc -shared -fPIC deck.c -o libDeck.so

clean:
	-rm prog libDeck.so 
