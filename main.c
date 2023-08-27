#include "monty.h"
global_var_t gl;

/**
 * main - Start Queue LIFO,Stack FILO program
 * @argc: Number of arguments
 * @argv: Pointer to arguments
 * Return: int value
 */
int main(int argc, char **argv)
{
void (*fun_p)(stack_t **stack, unsigned int line_number);
FILE *monty_f;
ssize_t num_of_line = 0;
size_t size_of_buf = BUF_SIZE;
char *break_line[2] = {NULL, NULL};

monty_check_arg(argc);
monty_f = fopen(argv[1], "r");
if (monty_f == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
init_gl(monty_f);
num_of_line = getline(&gl.buf, &size_of_buf, monty_f);
clean_spac(gl.buf);
while (num_of_line != -1)
{
break_line[0] = strtok(gl.buf, " \t\n");
if (break_line[0] && break_line[0][0] != '$')
{
remove_Dollar_From_End(break_line[0]);
fun_p = getopcodes(break_line[0]);
if (!fun_p)
{
fprintf(stderr, "L%u:", gl.cc);
fprintf(stderr, "unknown instruction %s\n", break_line[0]);
free_all_gl_var();
exit(EXIT_FAILURE);
}
gl.holder = strtok(NULL, " \t\n");
fun_p(&gl.head, gl.cc);
}
num_of_line = getline(&gl.buf, &size_of_buf, monty_f);
gl.cc++;
}
free_all_gl_var();
return (0);
}
