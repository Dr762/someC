  CC=gcc
 CFLAGS=-c
 LDFLAGS= -Wall
 SOURCES=longLine.c
 OBJECTS=$(SOURCES:.c=.o)
 EXECUTABLE=longLine
 
 all: $(SOURCES) $(EXECUTABLE)
 
 $(EXECUTABLE): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm
 
 .c.o:	
	$(CC) $(CFLAGS) $< -o $@ 
