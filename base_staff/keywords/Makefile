  CC=gcc
 CFLAGS=-c
 LDFLAGS= -Wall
 SOURCES=keywords.c
 OBJECTS=$(SOURCES:.c=.o)
 EXECUTABLE=keywords
 
 all: $(SOURCES) $(EXECUTABLE)
 
 $(EXECUTABLE): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm
 
 .c.o:	
	$(CC) $(CFLAGS) $< -o $@ 
