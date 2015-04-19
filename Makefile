all: df

df: df.c
	gcc -Wall -g df.c -o df

clean:
	rm -f df
