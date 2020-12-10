C=gcc
CFLAGS=-c
LDFLAGS= -Wall
SOURCES=child_process.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=cp

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm

.c.o:
	$(CC) $(CFLAGS) $< -o $@

