C=gcc
CFLAGS=-c
LDFLAGS= -Wall
SOURCES=map_demo.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=mp
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm

.c.o:
	$(CC) $(CFLAGS) $< -o $@

