  CC=gcc
 CFLAGS=-c
 LDFLAGS=
 SOURCES=stack.c stack_demo.c list.c
 OBJECTS=$(SOURCES:.c=.o)
 EXECUTABLE=st
 
 all: $(SOURCES) $(EXECUTABLE)
 
 $(EXECUTABLE): $(OBJECTS)
 	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
 
 .c.o:
 	$(CC) $(CFLAGS) $< -o $@