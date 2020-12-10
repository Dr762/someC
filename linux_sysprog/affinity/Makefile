C=gcc
CFLAGS=-c
LDFLAGS= -Wall
SOURCES=cpu_affinity.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=cpa

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm

.c.o:
	$(CC) $(CFLAGS) $< -o $@

