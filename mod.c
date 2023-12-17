#include "monty.h"

/**
 * mod - Computes the rest of the division of the second top element by the top element.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the Monty file.
 */
void mod(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->next;
    temp->n %= (*stack)->n;
    pop(stack, line_number);
}
