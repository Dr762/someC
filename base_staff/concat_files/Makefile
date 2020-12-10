  CC=gcc
 CFLAGS=-c
 LDFLAGS= -Wall
 SOURCES=concat_files.c
 OBJECTS=$(SOURCES:.c=.o)
 EXECUTABLE=concat
 
 all: $(SOURCES) $(EXECUTABLE)
 
 $(EXECUTABLE): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm
 
 .c.o:	
	$(CC) $(CFLAGS) $< -o $@ 
