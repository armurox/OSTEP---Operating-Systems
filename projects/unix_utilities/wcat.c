/*
Program that is meant to replicate the behaviour of the unix cat function. 
Takes in one ore more files and prints them out to the terminal one by one
*/
#include "io.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        exit(0);
    }

    // Print each file, or exit with error code for any one that fails
    for (int i = 1; i < argc; i++)
    {
        if (!print_file(argv[i]))
            print_error_message_and_return();
    }
}
