#include "monty.h"

/**
 * enqueue - Adds an element to the end of the queue.
 * @stack: A pointer to the front of the queue.
 * @n: The value to be added to the queue.
 */
void enqueue(stack_t **stack, int n)
{
    stack_t *new_node, *temp;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (*stack == NULL)
    {
        *stack = new_node;
    }
    else
    {
        temp = *stack;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = new_node;
        new_node->prev = temp;
    }
}
