C=gcc
CFLAGS=-c
LDFLAGS= -Wall
SOURCES=multi_signal_handler.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=msh
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm

.c.o:
	$(CC) $(CFLAGS) $< -o $@

