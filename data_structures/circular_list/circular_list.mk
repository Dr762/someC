  CC=gcc
 CFLAGS=-c
 LDFLAGS=
 SOURCES=circular_list.c circular_list_demo.c
 OBJECTS=$(SOURCES:.c=.o)
 EXECUTABLE=cll
 
 all: $(SOURCES) $(EXECUTABLE)
 
 $(EXECUTABLE): $(OBJECTS)
 $(CC) $(LDFLAGS) $(OBJECTS) -o $@
 
 .c.o:
 	$(CC) $(CFLAGS) $< -o $@ 