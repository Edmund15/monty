#include "monty.h"

/**
 * execute_opcode - Execute the opcode provided in a line of the Monty file.
 * @line: The line containing the opcode and its arguments.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the Monty file.
 */
void execute_opcode(char *line, stack_t **stack, unsigned int line_number)
{
    char *opcode;
    int value;

    opcode = strtok(line, " \t\n");

    if (opcode == NULL || opcode[0] == '#')
        return;

    if (strcmp(opcode, "push") == 0)
    {
        value = atoi(strtok(NULL, " \t\n"));
        push(stack, value, line_number);
    }
    else if (strcmp(opcode, "pall") == 0)
    {
        pall(stack, line_number);
    }
    else if (strcmp(opcode, "pint") == 0)
    {
        pint(stack, line_number);
    }
    else
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }
}
