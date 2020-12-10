C=gcc
CFLAGS=-c
LDFLAGS= -Wall
SOURCES=set_highest_priority.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=hp
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm

.c.o:
	$(CC) $(CFLAGS) $< -o $@

