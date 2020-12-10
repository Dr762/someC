C=gcc
CFLAGS=-c
LDFLAGS= -Wall
SOURCES=time_demo.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=tm
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm -lrt

.c.o:
	$(CC) $(CFLAGS) $< -o $@

