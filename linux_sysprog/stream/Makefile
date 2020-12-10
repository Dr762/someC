C=gcc
CFLAGS=-c
LDFLAGS= -Wall
SOURCES=stream_demo.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=str
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm

.c.o:
	$(CC) $(CFLAGS) $< -o $@

