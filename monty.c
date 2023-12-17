#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Entry point for the Monty interpreter.
 * @argc: The number of command-line arguments.
 * @argv: An array containing the command-line arguments.
 *
 * Return: Always 0 on success.
 */
int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    int read;
    stack_t *stack = NULL;
    unsigned int line_number = 0;
    int debug = 0;

    if (argc < 2 || argc > 3)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    if (argc == 3 && strcmp(argv[1], "-d") == 0)
    {
        debug = 1;
        file = fopen(argv[2], "r");
    }
    else
    {
        file = fopen(argv[1], "r");
    }

    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", (debug ? argv[2] : argv[1]));
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;

        if (line[0] == '#')
            continue;

        line[strcspn(line, "\n")] = '\0';

        execute_opcode(line, &stack, line_number);
    }

    free(line);
    fclose(file);
    free_stack(stack);

    return EXIT_SUCCESS;
}

