#include "monty.h"

/**
 * main - Entry point for the Monty interpreter.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * Return: Always 0.
 */
int main(int argc, char *argv[]) {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;
    stack_t *stack = NULL;

    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1) {
        line_number++;
        execute_custom_opcode(line, &stack, line_number);
    }

    fclose(file);
    free_stack(stack);
    free(line);

    return (0);
}

void execute_custom_opcode(char *line, stack_t **stack, unsigned int line_number) {
    char *opcode, *argument;
    opcode = strtok(line, " \t\n");
    if (opcode == NULL || *opcode == '#') {
        return;
    }

    argument = strtok(NULL, " \t\n");

    if (strcmp(opcode, "push") == 0) {
        if (argument == NULL || !is_number(argument)) {
            fprintf(stderr, "L%u: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
        int value = atoi(argument);
        push(stack, value);
    } else if (strcmp(opcode, "pall") == 0) {
        pall(stack, line_number);
    } else if (strcmp(opcode, "pop") == 0) {
        pop(stack, line_number);
    } else if (strcmp(opcode, "swap") == 0) {
        stack_swap(stack, line_number);
    } else {
        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }
}
