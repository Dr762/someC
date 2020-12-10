C=gcc
CFLAGS=-c
LDFLAGS= -Wall
SOURCES=rr_interval.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=rr
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm

.c.o:
	$(CC) $(CFLAGS) $< -o $@

