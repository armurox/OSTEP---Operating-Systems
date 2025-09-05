/*
Program that is meant to match the behaviour of the unix utility grep.
It basically searches through a file line-by-line for a user-specified search term
and prints out every line that matches it.
*/
#include "find.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    // If no arguments are provided, exit
    if (argc < 2)
    {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }

    // If only a search term is provided, read from stdin
    if (argc == 2)
    {
        print_found_lines(argv[1], "stdin");
        exit(0);
    }

    // Otherwise, read through every file, and print out each line that matches the user-specified search term
    // Note: exit if not able to open any particular file
    for (int i = 2; i < argc; i++)
    {
        if (!print_found_lines(argv[1], argv[2]))
        {
            printf("wgrep: cannot open file\n");
            exit(1);
        }
    }
}
