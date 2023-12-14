#include "monty.h"
/**
 * is_number - Checks if a string is a valid integer.
 * @str: The string to check.
 * Return: 1 if the string is a valid integer, 0 otherwise.
 */
int is_number(const char *str)
{
	 if (!str)
        return (0);

    for (int i = 0; str[i]; i++)
    {
        if (!isdigit(str[i]) && str[i] != '-')
            return (0);
    }
    return (1);
}

