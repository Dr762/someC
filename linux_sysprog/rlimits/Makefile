C=gcc
CFLAGS=-c
LDFLAGS= -Wall
SOURCES=rlimits.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=rl
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm

.c.o:
	$(CC) $(CFLAGS) $< -o $@

