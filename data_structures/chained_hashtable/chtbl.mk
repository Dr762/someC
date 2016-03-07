  CC=gcc
 CFLAGS=-c
 LDFLAGS=-g
 SOURCES=chtbl.c chtbl_demo.c list.c
 OBJECTS=$(SOURCES:.c=.o)
 EXECUTABLE=cht
 
 all: $(SOURCES) $(EXECUTABLE)
 
 $(EXECUTABLE): $(OBJECTS)
 	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
 
 .c.o:
 	$(CC) $(CFLAGS) $< -o $@