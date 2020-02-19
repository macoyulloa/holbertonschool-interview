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
	heap_t *tree;

	if (!root)
		return (NULL);
	tree = *root;
	if (!tree)
	{
		*root = binary_tree_node(tree, value);
		return (*root);
	}
	return (tree);
}
