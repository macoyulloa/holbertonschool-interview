#include "search.h"

/**
 * linear_skip -  searches for a value in a sorted skip int list
 *
 * @list: is a pointer to the head of the skip list to search in
 * @value: is the value to search for
 *
 * Return: pointer first node where value is located or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node, *node2;

	if (list == NULL)
		return (NULL);

	node = list;
	while (node->n <= value)
	{
		if (node->n == value)
			return (node);
		if (node->index < (size_t)value)
			node2 = node;
		node = node->express;
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
	}
	printf("Value found between indexes [%lu] and [%lu]\n", node2->index, node->index);
	for (; node2; node2 = node2->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", node2->index, node2->n);
		if (node2->n == value)
			return (node2);
	}
	return (NULL);
}
