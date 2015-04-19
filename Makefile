all: part

part: part.c
	gcc -Wall -g part.c -o part

clean:
	rm part
