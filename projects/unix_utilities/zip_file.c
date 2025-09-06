#include "find.h"  // Have already implemented the wgetline function, might as well reuse it:)
#include "zip_file.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>


#define NUMBER_OF_INTEGERS_TO_WRITE 1

/*
Encode a zip file using run-length-encoding and print it out to stdin
*/
void print_zipped_file(const char *filename)
{
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("wzip: cannot open file\n");
        exit(1);
    }

    // Allocate an initial line buffer of a default size
    char *line = calloc(sizeof(char), DEFAULT_LINE_LENGTH);
    if (line == NULL)
    {
        printf("wzip: ran out of memory!\n");
        fclose(f);
        exit(1);
    }
    int size = DEFAULT_LINE_LENGTH;
    int curr_size;
    
    // Read line by line into a memory buffer, then output to stdin the encoded version
    // TODO: Update wgetline to return -2 for newline, -1 for end of file
    while ((curr_size = wgetline(f, &line, &size)) != -1)
        print_zipped_line(line, curr_size);

    // Extra one at the end for the final line
    print_zipped_line(line, curr_size);
    // Cleanup memory
    fclose(f);
    free(line);
    line = NULL;
    
}


/*
Prints out the zipped version of a line using RLE (run-length encoding)
Paramaters:
1. line - Character array to be encoded
2. size - current size of the array
*/
void print_zipped_line(const char *line, int size)
{
    int32_t count = 1;
    char prev = line[0];
    for (int i = 1; i <= size; i++)
    {
        if (prev == line[i])
        {
            count++;
        }
        else
        {
            fwrite(&count, sizeof(int32_t), NUMBER_OF_INTEGERS_TO_WRITE, stdout); // Write precisely a 4 byte integer to stdout
            // printf("%d", count);
            putchar(prev);
            count = 1;
            prev = line[i];
        }
    }
}
