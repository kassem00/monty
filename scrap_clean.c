#include "monty.h"
/**
 * monty_check_arg - check argc
 * @argc: Number of arguments
 * Return: int value
 */
int monty_check_arg(int argc)
{
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
else
return (0);
}
/**
 * remove_Dollar_From_End - remove $ sign
 * @str: input string
 * Return: void
 */
void remove_Dollar_From_End(char *str)
{
size_t length;

if (str == NULL)
{
return;
}
length = strlen(str);
if (length == 0)
{
return;
}
if (str[length - 1] == '$')
{
str[length - 1] = '\0';

}
}


/**
 * clean_spac - remove space
 * @str: input string
 * Return: void
 */
void clean_spac(char *str)
{
char *source;
char *destination;
int foundText = 0;

if (str == NULL)
{
return;
}

source = str;
destination = str;

while (*source != '\0')
{
if (isspace(*source))
{
if (foundText)
{
*destination = *source;
destination++;
}
}
else
{
*destination = *source;
destination++;
foundText = 1;
}

source++;
}
*destination = '\0';
}
