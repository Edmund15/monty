#include "monty.h"

/**
 * mul - Multiplies the second top element with the top element of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the Monty file.
 */
void multiply(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->next;
    temp->n *= (*stack)->n;
    pop(stack, line_number);
}
