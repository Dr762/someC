C=gcc
CFLAGS=-c
LDFLAGS= -Wall
SOURCES=small_daemon.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=sd

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm

.c.o:
	$(CC) $(CFLAGS) $< -o $@

