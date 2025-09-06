CC := gcc
C_FLAGS := -std=c99 -Wall -Wextra -pedantic -Werror -I./headers

.PHONY: clean all

# Build all at once
all: wcat wgrep wzip

wcat: wcat.o io.o
	$(CC) $^ -o $@

wgrep: wgrep.o find.o
	$(CC) $^ -o $@

wzip: wzip.o zip_file.o find.o
	$(CC) $^ -o $@


# Build all object files
%.o: %.c
	$(CC) $(C_FLAGS) -c $^ -o $@

clean:
	rm -rf *.o *.exe *.dSYM *.aout
	rm -rf wcat
	rm -rf wgrep
	rm -rf wzip
