CC=gcc
CFLAGS=-c
LDFLAGS=
SOURCES=list.c list_demo.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=ll

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@
