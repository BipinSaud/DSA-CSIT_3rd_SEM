CC=gcc
CFLAGS=-Wall

# List all your C source files here
SOURCES=popDisplay.c popDisplayExit.c popExit.c pushDisplay.c pushDisplayExit.c pushPopDisplayExit.c

# Generate the names of the object files
OBJECTS=$(SOURCES:.c=.o)

# Generate the names of the binary files
BINARIES=$(SOURCES:.c=)

all: $(BINARIES)

# Compile each source file into an object file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link each object file into a binary file
%: %.o
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(BINARIES)
