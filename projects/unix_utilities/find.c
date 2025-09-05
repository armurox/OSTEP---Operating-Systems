#include "find.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEFAULT_LINE_LENGTH 1000

/* Read a line into a buffer, reallocating to increase the size of the buffer as needed
parameters:
1. sequence - The actual string that we are reading from
2. buffer - The character buffer which we are reading into, will increase as needed
3. buffer_size - The size of the buffer, will increase as needed

return value - returns the number of characters that were successfully read, or -1.
This matches the standard behaviour of getline, as per the man page
*/
int wgetline(FILE *f, char **buffer, int *buffer_size)
{
    char c;
    int curr_index = 0;
    char *temp = NULL;
    while ((c = fgetc(f)) != EOF && c != '\n')
    {   
        if (curr_index == *buffer_size)
        {
            (*buffer_size) *= 2;
            temp = realloc(*buffer, *buffer_size);
            if (temp == NULL)
            {
                printf("wgrep: ran out of memory!\n");
                fclose(f);
                // Free the array itself
                free(*buffer);
                exit(1);
            }
            *buffer = temp;
        }

        // TODO: Actually read into the line and increment curr_index
        (*buffer)[curr_index++] = c;
    }

    // In the special edge case when we have read everything into the buffer, allocate one more than previous
    // since we now need to allocate the null character
    if (curr_index == *buffer_size)
    {
        (*buffer_size)++;
        temp = realloc(*buffer, *buffer_size);
        if (temp == NULL)
        {
            printf("wgrep: ran out of memory!\n");
            fclose(f);
            free(*buffer);
            exit(1);
        }
        *buffer = temp;
    }

    (*buffer)[curr_index] = '\0';

    return (c == EOF) ? -1 : curr_index;
}


int search_term_in_line(const char *search_term, const char *line)
{
    int matched_length = 0;
    int prev_matched = 0;
    for (int i = 0; line[i] != '\0' && search_term[matched_length] != '\0'; i++)
    {
        if (search_term[matched_length] == line[i] && prev_matched)
            matched_length++;
        else if (search_term[matched_length] == line[i])
        {
            matched_length = 1;
            prev_matched = 1;
        }
        else
        {
            matched_length = 0;
            prev_matched = 0;
        }
    }

    return matched_length == (int) strlen(search_term);
}


int print_found_lines(const char *search_term, const char *filename)
{
    FILE *f = (strcmp(filename, "stdin") == 0) ? stdin : fopen(filename, "r");
    if (f == NULL)
    {
        printf("wgrep: cannot open file\n");
        exit(1);
    }

    // Allocate an initial line buffer of a default size
    char *line = malloc(sizeof(char) * DEFAULT_LINE_LENGTH);
    if (line == NULL)
    {
        printf("wgrep: ran out of memory!\n");
        fclose(f);
        exit(1);
    }
    int size = DEFAULT_LINE_LENGTH;

    // Keep reading each line into the line buffer until the end, printing out the lines with the search term
    while (wgetline(f, &line, &size) != -1)
    {
        if (search_term_in_line(search_term, line))
        {
            printf("%s\n", line);
        }
    }

    fclose(f);
    free(line);
    return 1;
}
