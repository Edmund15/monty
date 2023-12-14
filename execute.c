#include "monty.h"

/**
 * execute - Interpret and execute Monty bytecode instructions
 * @content: Line content from Monty bytecode file
 * @stack: Pointer to the top of the stack
 * @counter: Line number in the Monty bytecode file
 * @file: File pointer for potential error messages
 */
void execute(char *content, stack_t **stack, unsigned int counter, FILE *file __attribute__((unused)))
{
    char *opcode;
    void (*op_func)(stack_t **, unsigned int);

    opcode = strtok(content, " \t\n");

    if (!opcode || opcode[0] == '#')
        return;

    op_func = get_op_func(opcode);

    if (!op_func)
    {
        fprintf(stderr, "L%u: unknown instruction %s\n", counter, opcode);
        exit(EXIT_FAILURE);
    }

    op_func(stack, counter);
}
