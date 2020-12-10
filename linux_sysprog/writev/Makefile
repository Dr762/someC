C=gcc
CFLAGS=-c
LDFLAGS= -Wall
SOURCES=writev_demo.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=wd
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm

.c.o:
	$(CC) $(CFLAGS) $< -o $@

