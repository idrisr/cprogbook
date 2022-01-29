SHELL=/usr/bin/zsh
CC=clang
CFLAGS=-g -Wall

.PHONY: clean

ex1-22: ex1-22.c
	$(CC) $(CFLAGS) ex1-22.c -o $@

test: ex1-22
	./test-runner.sh

clean:
	rm ex1-22
