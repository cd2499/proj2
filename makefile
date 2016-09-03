all: ./main.c
	gcc -Wall -o gash ./main.c -lreadline -lcurses
