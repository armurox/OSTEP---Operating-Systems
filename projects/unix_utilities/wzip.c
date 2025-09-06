/*
Program that is meant to replicate the basic functionality of unix's zip shell command.
Given a sequence of files, it will compress them using run-length encoding (RLE),
which basically means that given a sequence of n characters of the same type in a row, it will be turned into
n and a single instance of the character
*/
#include "zip_file.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("wzip: file 1 [file 2 ...]\n");
        exit(1);
    }

    // TODO: Update to read in all files in one short, with argc as an argument. It will allow compressing multiple files into one.
    for (int i = 1; i < argc; i++)
        print_zipped_file(argv[i]);
}
