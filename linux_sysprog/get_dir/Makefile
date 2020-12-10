C=gcc
CFLAGS=-c
LDFLAGS= -Wall
SOURCES=get_dir.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=gd

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm

.c.o:
	$(CC) $(CFLAGS) $< -o $@

