all: ./main.c
	gcc -Wall -o gash ./process_cmd.c ./main.c ./internal_cmd.c -lreadline -lcurses
