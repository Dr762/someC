  CC=gcc
 CFLAGS=-c
 LDFLAGS= -Wall
 SOURCES=inputCounter.c
 OBJECTS=$(SOURCES:.c=.o)
 EXECUTABLE=inputCounter
 
 all: $(SOURCES) $(EXECUTABLE)
 
 $(EXECUTABLE): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm
 
 .c.o:	
	$(CC) $(CFLAGS) $< -o $@ 
