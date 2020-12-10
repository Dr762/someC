C=gcc
CFLAGS=-c
LDFLAGS= -Wall
SOURCES=get_alloc_size.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=gs

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm

.c.o:
	$(CC) $(CFLAGS) $< -o $@

