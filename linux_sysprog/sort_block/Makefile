C=gcc
CFLAGS=-c
LDFLAGS= -Wall
SOURCES=sort_block.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=sb
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm

.c.o:
	$(CC) $(CFLAGS) $< -o $@

