#include "monty.h"

int current_mode = 0;
bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - monty code interpreter
 * @argc: number of arguments
 * @argv: monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[]) {
    char *content;
    FILE *file;
    size_t size = 0;
    ssize_t read_line = 1;
    stack_t *stack = NULL;
    unsigned int counter = 0;

    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    bus.file = file;
    if (!file) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (read_line > 0) {
        content = NULL;
        read_line = getline(&content, &size, file);
        bus.content = content;
        counter++;
        if (read_line > 0) {
            execute_custom_opcode(content, &stack, counter);
        }
        free(content);
    }

    free_stack(stack);
    fclose(file);

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

