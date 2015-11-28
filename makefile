madshell: main.o shell.o
	gcc main.o shell.o parser.o -o madshell
main.o: main.c
	gcc -c main.c
parser.o: parser.c
	gcc -c parser.c
shell.o: shell.c
	gcc -c shell.c
run: madshell
	./madshell
clean:
	rm main.o shell.o madshell
