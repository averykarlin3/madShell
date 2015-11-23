madshell: main.o shell.o
	gcc main.o shell.o -o madshell
main.o: main.c
	gcc -c main.c
shell.o: shell.c
	gcc -c shell.c
run: madshell
	./madshell
clean:
	rm main.o shell.o madshell
