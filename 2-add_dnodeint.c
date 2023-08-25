#include "monty.h"

/**
 * add_dnodeint - function that add node in head
 * @head:linked list node
 * @n:data to store in new node
 * Return: size_t which number of node
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
		return (NULL);
	new->n = n;
	new->prev = NULL;

	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
	}
	else
	{
		new->next = *head;
		(*head)->prev = new;
		*head = new;
	}
	return (new);
}
