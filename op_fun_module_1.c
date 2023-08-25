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
    int n, j;

    if (!gl.holder)
    {
        fprintf(stderr, "L%u: ", cline);
        fprintf(stderr, "usage: push integer\n");
		free_all_gl_var();
        exit(EXIT_FAILURE);
    }

    for (j = 0; gl.holder[j] != '\0'; j++)
    {
        if (!isdigit(gl.holder[j]) && gl.holder[j] != '-')
        {
            fprintf(stderr, "L%u: ", cline);
            fprintf(stderr, "usage: push integer\n");
            free_all_gl_var();
            exit(EXIT_FAILURE);
        }
    }

    n = atoi(gl.holder);

    if (gl.working_ident == 1)
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
    stack_t *aux;
    (void)cline;

    aux = *doubly;

    while (aux)
    {
        printf("%d\n", aux->n);
        aux = aux->next;
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
        fprintf(stderr, "L%u: ", cline);
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
    stack_t *aux;

    if (doubly == NULL || *doubly == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", cline);
        free_all_gl_var();
        exit(EXIT_FAILURE);
    }
    aux = *doubly;
    *doubly = (*doubly)->next;
    free(aux);
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
    stack_t *aux = NULL;

    aux = *doubly;

    for (; aux != NULL; aux = aux->next, m++)
        ;

    if (m < 2)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", cline);
        free_all_gl_var();
        exit(EXIT_FAILURE);
    }

    aux = *doubly;
    *doubly = (*doubly)->next;
    aux->next = (*doubly)->next;
    aux->prev = *doubly;
    (*doubly)->next = aux;
    (*doubly)->prev = NULL;
}
