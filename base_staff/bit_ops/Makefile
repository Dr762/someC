  CC=gcc
 CFLAGS=-c
 LDFLAGS= -Wall
 SOURCES=bit_ops.c
 OBJECTS=$(SOURCES:.c=.o)
 EXECUTABLE=bitops
 
 all: $(SOURCES) $(EXECUTABLE)
 
 $(EXECUTABLE): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm
 
 .c.o:	
	$(CC) $(CFLAGS) $< -o $@ 
