#include "sort.h"

/**
 * swap_handler - swap nodes of doubly linked list
 * @head: head of linked list
 * @node1: pointer to first node
 * @node2: pointer to second node
 */
void swap_handler(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - insertion sort on doubly linked list
 * @list: pointer to head of doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *index, *current, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (index = (*list)->next; index != NULL; index = tmp)
	{
		tmp = index->next;
		current = index->prev;
		while (current != NULL && index->n < current->n)
		{
			swap_handler(list, &current, index);
			print_list((const listint_t *)*list);
		}
	}
}
