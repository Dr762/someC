C=gcc
CFLAGS=-c
LDFLAGS= -Wall
SOURCES=select_demo.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=sel
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm

.c.o:
	$(CC) $(CFLAGS) $< -o $@

