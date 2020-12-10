CC=gcc
CFLAGS=-c
LDFLAGS=
SOURCES=queue.c queue_demo.c list.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=qu
 
all: $(SOURCES) $(EXECUTABLE)
 
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
 
.c.o:
	$(CC) $(CFLAGS) $< -o $@
