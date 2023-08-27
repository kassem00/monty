#include "monty.h"

/**
 * div_stack - divides the second top element
 * of the stack by the top element of the stack.
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: void
 */
void div_stack(stack_t **doubly, unsigned int cline)
{
	int i = 0;
	stack_t *temp = NULL;

	temp = *doubly;

	for (; temp != NULL; temp = temp->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", cline);
		free_all_gl_var();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", cline);
		free_all_gl_var();
		exit(EXIT_FAILURE);
	}

	temp = (*doubly)->next;
	temp->n /= (*doubly)->n;
	pop(doubly, cline);
}

/**
 * mul - multiplies the second top element
 * of the stack with the top element of the stack.
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: void
 */
void mul(stack_t **doubly, unsigned int cline)
{
	int i = 0;
	stack_t *temp = NULL;

	temp = *doubly;

	for (; temp != NULL; temp = temp->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", cline);
		free_all_gl_var();
		exit(EXIT_FAILURE);
	}

	temp = (*doubly)->next;
	temp->n *= (*doubly)->n;
	pop(doubly, cline);
}

/**
 * mod - computes the rest of the division of the second element
 * by the top element of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: void
 */
void mod(stack_t **doubly, unsigned int cline)
{
	int i = 0;
	stack_t *temp = NULL;

	temp = *doubly;

	for (; temp != NULL; temp = temp->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", cline);
		free_all_gl_var();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", cline);
		free_all_gl_var();
		exit(EXIT_FAILURE);
	}

	temp = (*doubly)->next;
	temp->n %= (*doubly)->n;
	pop(doubly, cline);
}
/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: void
 */
void pchar(stack_t **doubly, unsigned int cline)
{
	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", cline);
		free_all_gl_var();
		exit(EXIT_FAILURE);
	}
	if ((*doubly)->n < 0 || (*doubly)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", cline);
		free_all_gl_var();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*doubly)->n);
}

/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 *
 * @doubly: head
 * @cline: line number;
 * Return: void
 */
void pstr(stack_t **doubly, unsigned int cline)
{
	stack_t *temp;
	(void)cline;

	temp = *doubly;

	while (temp && temp->n > 0 && temp->n < 128)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}

	printf("\n");
}
