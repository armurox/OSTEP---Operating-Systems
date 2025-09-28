CC := gcc
C_FLAGS := -Wall -Wextra -pedantic

.PHONY: all clean


all: cpu io mem threads

cpu: cpu.o
	$(CC) $^ -o $@

# Build object files
%.o: %.c
	$(CC) $(C_FLAGS) -c $^ 


clean:
	rm -rf *.o
	rm -rf clean
