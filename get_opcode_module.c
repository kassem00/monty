#include "monty.h"

/**
 * getopcodes - selects opcode
 *
 * @in_opcode: opcode passed
 *
 * Return: pointer to  function
 */
void (*getopcodes(char *in_opcode))(stack_t **stack, unsigned int line_number)
{
instruction_t instruct[] = {
{"push", push},
{"pall", pall},
{"pint", pint},
{"pop", pop},
{"swap", swap},
{"queue", queue},
{"stack", stack},
{"add", add},
{"nop", nop},
{"sub", sub},
{"mul", mul},
{"div", div_stack},
{"mod", mod},
{"pchar", pchar},
{"pstr", pstr},
{"rotl", rotl},
{"rotr", rotr},
{NULL, NULL}};
int i = 0;
/* printf(" \ninput \t%s ", in_opcode); */
while (1)
{
if (strcmp(instruct[i].opcode, in_opcode) == 0)
break;
i++;
}
/*printf(" \tfound %d %s\n", i,instruct->opcode);*/
return (instruct[i].f);
}

/**
 * free_all_gl_var - frees globals
 *
 * Return: void
 */
void free_all_gl_var(void)
{
free_dlistint(gl.head);
free(gl.buf);
fclose(gl.monty_f);
}

/**
 * init_gl - initializes globals
 *
 * @fd: file descriptor
 * Return: void
 */

void init_gl(FILE *fd)
{
gl.working_ident = STACK_;
gl.cc = 1;
gl.holder = NULL;
gl.head = NULL;
gl.monty_f = fd;
gl.buf = malloc(sizeof(char) * BUF_SIZE);
}

/**
 * queue - (FIFO)
 *
 * @doubly: head of the linked list
 * @line_number: line number;
 * Return: void
 */
void queue(stack_t **doubly, unsigned int line_number)
{
(void)doubly;
(void)line_number;
gl.working_ident = QUEUE_;
}

/**
 * stack - (LIFO)
 *
 * @doubly: head
 * @line_number: line number;
 * Return: void
 */
void stack(stack_t **doubly, unsigned int line_number)
{
(void)doubly;
(void)line_number;
gl.working_ident = STACK_;
}
