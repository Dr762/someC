  CC=gcc
 CFLAGS=-c
 LDFLAGS= -Wall
 SOURCES=lineSort.c
 OBJECTS=$(SOURCES:.c=.o)
 EXECUTABLE=lineSort
 
 all: $(SOURCES) $(EXECUTABLE)
 
 $(EXECUTABLE): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm
 
 .c.o:	
	$(CC) $(CFLAGS) $< -o $@ 
