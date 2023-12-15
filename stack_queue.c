#include "monty.h"

/**
 * stack - Sets the format of the data to a stack (LIFO).
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the Monty byte code file.
 */
void stack(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    current_mode = 0;
}

/**
 * queue - Sets the format of the data to a queue (FIFO).
 * @stack: A pointer to the front of the queue.
 * @line_number: The line number in the Monty byte code file.
 */
void queue(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    current_mode = 1;
}
