 CC=gcc
 CFLAGS=-c
 LDFLAGS=
 SOURCES=double_list.c double_linked_list_demo.c
 OBJECTS=$(SOURCES:.c=.o)
 EXECUTABLE=dll
 
 all: $(SOURCES) $(EXECUTABLE)
 
 $(EXECUTABLE): $(OBJECTS)
 	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
 
 .c.o:
 	$(CC) $(CFLAGS) $< -o $@ 