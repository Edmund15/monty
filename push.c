#include "monty.h"
/**
 * push - Pushes an element onto the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the Monty byte code file.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \n");
	int n;

	if (!arg || !is_number(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = atoi(arg);

	stack_push(stack, n);
}
