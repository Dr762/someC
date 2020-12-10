C=gcc
CFLAGS=-c
LDFLAGS= -Wall
SOURCES=change_group.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=cgg

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm

.c.o:
	$(CC) $(CFLAGS) $< -o $@

