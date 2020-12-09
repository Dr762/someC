  CC=gcc
 CFLAGS=-c
 LDFLAGS= -Wall
 SOURCES=base.c
 OBJECTS=$(SOURCES:.c=.o)
 EXECUTABLE=base
 
 all: $(SOURCES) $(EXECUTABLE)
 
 $(EXECUTABLE): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm
 
 .c.o:	
	$(CC) $(CFLAGS) $< -o $@ 
