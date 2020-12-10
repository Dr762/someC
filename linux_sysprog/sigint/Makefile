C=gcc
CFLAGS=-c
LDFLAGS= -Wall
SOURCES=sigint_handler.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=sh
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm

.c.o:
	$(CC) $(CFLAGS) $< -o $@

