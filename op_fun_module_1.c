#include "monty.h"
/**
 * push - pushes an element to the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void push(stack_t **doubly, unsigned int cline)
{
int n, i;
char *temp = NULL;
temp = strtok(gl.holder, "$");
if (temp != NULL)
{
NULL;
}
else
{ /* if temp point to null */
fprintf(stderr, "L%u:", cline);
fprintf(stderr, "usage: push integer\n");
free_all_gl_var();
exit(EXIT_FAILURE);
}

for (i = 0; temp[i] != '\0'; i++)
{
if (!isdigit(temp[i]))
{
fprintf(stderr, "L%u:", cline);
fprintf(stderr, "usage: push integer\n");
free_all_gl_var();
exit(EXIT_FAILURE);
}
}

n = atoi(temp);

if (gl.working_ident == STACK_)
add_dnodeint(doubly, n);
else
add_dnodeint_end(doubly, n);
}

/**
 *pall - prints all values on the stack
 *
 * @doubly: head of the linked list
 * @cline: line numbers
 * Return: no return
 */
void pall(stack_t **doubly, unsigned int cline)
{
stack_t *tem;
(void)cline;

tem = *doubly;

while (tem != NULL)
{
fprintf(stdout, "%d\n", tem->n);
tem = tem->next;
}
}

/**
 *pint - prints the value at the top of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void pint(stack_t **doubly, unsigned int cline)
{
(void)cline;
if (*doubly == NULL)
{
fprintf(stderr, "L%u:", cline);
fprintf(stderr, "can't pint, stack empty\n");
free_all_gl_var();
exit(EXIT_FAILURE);
}

printf("%d\n", (*doubly)->n);
}

/**
 *pop - removes the top element of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void pop(stack_t **doubly, unsigned int cline)
{
stack_t *temp;

if (doubly == NULL || *doubly == NULL)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", cline);
free_all_gl_var();
exit(EXIT_FAILURE);
}
temp = *doubly;
*doubly = (*doubly)->next;
free(temp);
}

/**
 *swap - swaps the top two elements of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void swap(stack_t **doubly, unsigned int cline)
{
int m = 0;
stack_t *temp = NULL;

temp = *doubly;

for (; temp != NULL; temp = temp->next, m++)
;

if (m < 2)
{
fprintf(stderr, "L%u: can't swap, stack too short\n", cline);
free_all_gl_var();
exit(EXIT_FAILURE);
}

temp = *doubly;
*doubly = (*doubly)->next;
temp->next = (*doubly)->next;
temp->prev = *doubly;
(*doubly)->next = temp;
(*doubly)->prev = NULL;
}
