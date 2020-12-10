CC=gcc
CFLAGS=-c
LDFLAGS= -Wall
SOURCES=encrypt.c bit_ops.c encryption_demo.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=enc
 
all: $(SOURCES) $(EXECUTABLE)
 
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm
 
.c.o:	
	$(CC) $(CFLAGS) $< -o $@ 
