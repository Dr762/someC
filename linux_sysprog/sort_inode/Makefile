C=gcc
CFLAGS=-c
LDFLAGS= -Wall
SOURCES=sort_inode.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=si
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm

.c.o:
	$(CC) $(CFLAGS) $< -o $@

