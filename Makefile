CC=gcc
CFLAGS=-Wall -Wextra -std=c99

TARGETS = my_octave

build: $(TARGETS)

my_octave: my_octave.c
	$(CC) $(CFLAGS) my_octave.c  -o my_octave

pack:
	zip -FSr 311CA_GutanuTiberiu-Mihnea_Tema2.zip README Makefile *.c *.h

clean:
	rm -f $(TARGETS)

.PHONY: pack clean
