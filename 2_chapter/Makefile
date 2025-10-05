CC := gcc
C_FLAGS := -Wall -Wextra -pedantic

.PHONY: all clean


all: cpu io mem threads

# Main programs in final executable
cpu: cpu.o
	$(CC) $^ -o $@

mem: mem.o
	$(CC) $^ -o $@

threads: threads.o
	$(CC) $^ -o $@

io: io.o
	$(CC) $^ -o $@

# Build object files
%.o: %.c
	$(CC) $(C_FLAGS) -c $^ 


clean:
	rm -rf *.o
	rm -rf cpu
	rm -rf mem
	rm -rf threads
	rm -rf io
