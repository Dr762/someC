C=gcc
CFLAGS=-c
LDFLAGS= -Wall
SOURCES=find_file.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=ff

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm

.c.o:
	$(CC) $(CFLAGS) $< -o $@

