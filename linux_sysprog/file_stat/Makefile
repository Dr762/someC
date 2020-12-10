C=gcc
CFLAGS=-c
LDFLAGS= -Wall
SOURCES=file_stat.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=fs

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm

.c.o:
	$(CC) $(CFLAGS) $< -o $@

