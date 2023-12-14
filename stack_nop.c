#include "monty.h"

/**
 * stack_nop - Does nothing.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the Monty byte code file.
 */
void stack_nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}
