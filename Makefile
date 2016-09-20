CC=gcc
CFLAGS=-Wall -c
LDFLAGS=
DIRBUILD=build
DIRSRC=src
SOURCES=$(shell ls $(DIRSRC)/*.c)
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=$(DIRBUILD)/main


all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE):
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

$(SOURCES):
	$(CC) $(CFLAGS) $@
	mv *.o $(DIRSRC)

clean:
	rm $(OBJECTS) $(EXECUTABLE)
