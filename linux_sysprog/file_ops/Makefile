C=gcc
CFLAGS=-c
LDFLAGS= -Wall
SOURCES=file_ops.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=fo

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm

.c.o:
	$(CC) $(CFLAGS) $< -o $@

