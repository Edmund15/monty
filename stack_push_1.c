#include "monty.h"

/**
 * stack_push - Adds a new element to the top of the stack.
 * @stack: A pointer to the top of the stack.
 * @n: The value to be added to the stack.
 * @line_number: The line number in the Monty byte code file.
 */
void stack_push(stack_t **stack, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;

	if (*stack != NULL)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	else
	{
		new_node->next = NULL;
	}

	*stack = new_node;
}
