#include "binary_trees.h"

/**
 * heap_insert - insert a heap
 * @root: pointer to a root.
 * @value: value to put in the new node.
 *
 * Return: return a pointer to the new node, or NULL on failure.
 */

heap_t *heap_insert(heap_t **root, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	new_node->left = new_node->right = NULL;
	new_node->n = value;
	new_node->parent = parent;

	return (new_node);
}
