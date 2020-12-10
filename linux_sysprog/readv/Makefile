C=gcc
CFLAGS=-c
LDFLAGS= -Wall
SOURCES=readv_demo.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=rd
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm

.c.o:
	$(CC) $(CFLAGS) $< -o $@

