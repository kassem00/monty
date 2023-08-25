#include "monty.h"
/**
 * add - adds the top two elements of the stack
 *
 * @doubly: head of the linked list
 * @ line_number: line number;
 * Return: void
 */
void add(stack_t **doubly, unsigned int line_number)
{
    int m = 0;
    stack_t *aux = NULL;

    aux = *doubly;

    for (; aux != NULL; aux = aux->next, m++)
        ;

    if (m < 2)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        free_all_gl_var();
        exit(EXIT_FAILURE);
    }

    aux = (*doubly)->next;
    aux->n += (*doubly)->n;
    pop(doubly, line_number);
}

/**
 * nop - doesn't do anythinhg
 *
 * @doubly: head
 * @ line_number: line number;
 * Return: void
 */
void nop(stack_t **doubly, unsigned int line_number)
{
    (void)doubly;
    (void)line_number;
}