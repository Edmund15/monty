#include "monty.h"
/**
 * get_op_func - Selects the correct function to perform the operation.
 * @opcode: The operation code.
 *
 * Return: A pointer to the corresponding function, or NULL if not found.
 */
void (*get_op_func(char *opcode))(stack_t **, unsigned int)
{
	instruction_t opcodes[] = 
	{
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"add", stack_add},
		{"pop", pop},
		{"swap", stack_swap},
		{"nop", stack_nop},
		{NULL, NULL}
	};

	int i = 0;

	while (opcodes[i].opcode)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
			return (opcodes[i].f);
		i++;
	}
	return (NULL);
}
