C=gcc
CFLAGS=-c
LDFLAGS= -Wall
SOURCES=send_sighup.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=ss
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm

.c.o:
	$(CC) $(CFLAGS) $< -o $@

