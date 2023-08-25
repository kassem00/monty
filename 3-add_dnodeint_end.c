#include "monty.h"

/**
 * add_dnodeint_end - function that add node in end of list
 * @head:linked list node
 * @n:data to store in new node
 * Return: node
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *temp;

	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
	}
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
	return (new);
}
