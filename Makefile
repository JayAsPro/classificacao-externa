CC = gcc

bin/arquivoBinario: bin/arquivoBinario.o
	$(CC) bin/arquivoBinario.o

bin/arquivoBinario.o: src/arquivoBinario.c
	$(CC) src/arquivoBinario.c -o bin/arquivoBinario.o