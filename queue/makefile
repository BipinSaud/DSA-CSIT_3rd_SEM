CC=gcc
CFLAGS=-Wall

# List all your C source files here
SOURCES=circularQueueComplete.c enqueueDisplayExit.c dequeueDisplayExit.c linearQueueComplete.c

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
