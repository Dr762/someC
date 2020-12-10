C=gcc
CFLAGS=-c
LDFLAGS= -Wall
SOURCES=signal_payload.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=sp
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm

.c.o:
	$(CC) $(CFLAGS) $< -o $@

