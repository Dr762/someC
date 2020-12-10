C=gcc
CFLAGS=-c
LDFLAGS= -Wall
SOURCES=stat.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=st
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm

.c.o:
	$(CC) $(CFLAGS) $< -o $@

