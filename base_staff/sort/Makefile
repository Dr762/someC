  CC=gcc
 CFLAGS=-c
 LDFLAGS= -Wall
 SOURCES=sort.c
 OBJECTS=$(SOURCES:.c=.o)
 EXECUTABLE=sort
 
 all: $(SOURCES) $(EXECUTABLE)
 
 $(EXECUTABLE): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm
 
 .c.o:	
	$(CC) $(CFLAGS) $< -o $@ 
