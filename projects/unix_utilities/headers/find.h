#include <stdio.h>
#ifndef FIND_H
#define FIND_H

#define DEFAULT_LINE_LENGTH 1000
int print_found_lines(const char *search_term, const char *filename);
int wgetline(FILE *f, char **buffer, int *buffer_size);
int search_term_in_line(const char *search_term, const char *line);

#endif
