#ifndef _MONTY_H_
#define _MONTY_H_
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

extern int current_mode;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct bus_s - Struct for the interpreter state
 * @file: FILE pointer to the currently open file
 * @content: current line being processed
 * @stack: doubly linked list representation of the stack
 * @line_number: current line number in the file
 */
typedef struct bus_s
{
    FILE *file;
    char *content;
    stack_t *stack;
    unsigned int line_number;
} bus_t;


void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

void (*get_op_func(char *opcode))(stack_t **, unsigned int);
void pint(stack_t **stack, unsigned int line_number);
int is_number(const char *str);
void pop(stack_t **stack, unsigned int line_number);
void stack_push(stack_t **stack, int n);
void stack_swap(stack_t **stack, unsigned int line_number);
void stack_add(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);

void stack_pop(stack_t **stack, unsigned int line_number);
void stack_nop(stack_t **stack, unsigned int line_number);
int main(int argc, char *argv[]);
void free_stack(stack_t *stack);
void execute(char *content, stack_t **stack, unsigned int counter, FILE *file __attribute__((unused)));
void sub(stack_t **stack, unsigned int line_number);
void div_op(stack_t **stack, unsigned int line_number);
void mul_op(stack_t **stack, unsigned int line_number);
void mod_op(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void execute_custom_opcode(char *line, stack_t **stack, unsigned int line_number);
void enqueue(stack_t **queue, int value);
void free_stack(stack_t *stack);
void stack_push(stack_t **stack, int n);
int main(int argc, char *argv[]);
int execute_custom_opcode(stack_t **stack, char *opcode, unsigned int line_number);
#endif /* _MONTY_H_ */
