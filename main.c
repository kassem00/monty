#include "monty.h"

/**
 * main - Start Queue LIFO,Stack FILO program
 * @argc: Number of arguments
 * @argv: Pointer to arguments
 * Return: int value
 */
int main(int argc, char **argv)
{
	/*	char buf[1024]; */
	FILE *monty_f;
	char *buf;
	ssize_t num_of_line = 0;
	size_t size_of_buf = 256;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	monty_f = fopen(argv[1], "r");

	if (monty_f == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/*	fread(&buf, sizeof(buf), 2, monty_f);
	 */

	num_of_line = getline(&buf, &size_of_buf, monty_f);
	while (num_of_line != -1)
	{
		/*printf("%s", buf);	*/
		num_of_line = getline(&buf, &size_of_buf, monty_f);
	}
	return (0);
}
