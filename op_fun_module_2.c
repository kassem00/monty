#include "monty.h"
/**
 * add - adds the top two elements of the stack
 *
 * @doubly: head of the linked list
 * @line_number: line number;
 * Return: void
 */
void add(stack_t **doubly, unsigned int line_number)
{
int m = 0;
stack_t *temp = NULL;

temp = *doubly;

for (; temp != NULL; temp = temp->next, m++)
;

if (m < 2)
{
fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
free_all_gl_var();
exit(EXIT_FAILURE);
}

temp = (*doubly)->next;
temp->n += (*doubly)->n;
pop(doubly, line_number);
}

/**
 * nop - doesn't do anythinhg
 *
 * @doubly: head
 * @line_number: line number;
 * Return: void
 */
void nop(stack_t **doubly, unsigned int line_number)
{
(void)doubly;
(void)line_number;
}


/**
 * sub - subtracts two elements from the top
 *
 * @doubly: head
 * @cline: line number
 * Return: void
 */
void sub(stack_t **doubly, unsigned int cline)
{
int i = 0;
stack_t *temp = NULL;

temp = *doubly;

for (; temp != NULL; temp = temp->next, i++)
;

if (i < 2)
{
dprintf(2, "L%u: can't sub, stack too short\n", cline);
free_all_gl_var();
exit(EXIT_FAILURE);
}

temp = (*doubly)->next;
temp->n -= (*doubly)->n;
pop(doubly, cline);
}



/**
 * rotl - rotates the first element to the bottom and  the second to the top
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: void
 */
void rotl(stack_t **doubly, unsigned int cline)
{
	stack_t *temp1 = NULL;
	stack_t *temp2 = NULL;
	(void)cline;

	if (*doubly == NULL)
		return;

	if ((*doubly)->next == NULL)
		return;

	temp1 = (*doubly)->next;
	temp2 = *doubly;

	for (; temp2->next != NULL; temp2 = temp2->next)
		;

	temp1->prev = NULL;
	temp2->next = *doubly;
	(*doubly)->next = NULL;
	(*doubly)->prev = temp2;
	*doubly = temp1;
}

/**
 * rotr - reverse the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: void
 */
void rotr(stack_t **doubly, unsigned int cline)
{
	stack_t *temp = NULL;
	(void)cline;

	if (*doubly == NULL)
		return;

	if ((*doubly)->next == NULL)
		return;

	temp = *doubly;

	for (; temp->next != NULL; temp = temp->next)
		;

	temp->prev->next = NULL;
	temp->next = *doubly;
	temp->prev = NULL;
	(*doubly)->prev = temp;
	*doubly = temp;
}
