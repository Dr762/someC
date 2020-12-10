C=gcc
CFLAGS=-c
LDFLAGS= -Wall
SOURCES=rr_priority_range.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=rrp
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm

.c.o:
	$(CC) $(CFLAGS) $< -o $@

