#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the Monty byte code file.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *first = *stack;
    stack_t *last = *stack;

    (void)line_number;

    if (first && first->next)
    {
        while (last->next)
            last = last->next;

        first->next->prev = NULL;
        last->next = first;
        first->prev = last;
        *stack = first->next;
        last->next = NULL;
    }
}
